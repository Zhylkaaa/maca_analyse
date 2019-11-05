#include "maca_analyse.h"

std::string maca_analyse(std::string config, std::string toki_config_path, std::string input_text, bool linewise, bool split_chunks) {
	std::string input_format = "txt", output_format = "plain";

	//TODO: test with custom config 
	if (!toki_config_path.empty()) {
		Toki::Path::Instance().set_search_path(toki_config_path);
    }

	if (!config.empty()) {
			static boost::shared_ptr<Maca::SentenceAnalyser> sa = Maca::SentenceAnalyser::create_from_named_config(config);

			static std::stringstream out_stream;
			static boost::shared_ptr<Corpus2::TokenWriter> writer = Corpus2::TokenWriter::create_stream_writer(output_format, out_stream, sa->tagset());

			std::stringstream input_stream(input_text);
			
			if(linewise){
				std::string line;
				while (std::getline(input_stream, line)) {
					sa->set_input_source(UnicodeString::fromUTF8(line));
					while (Corpus2::Sentence::Ptr sentence = sa->get_next_sentence()) {
						writer->write_sentence(*sentence);
					}
				}
			} else {
				boost::shared_ptr<Corpus2::TokenReader> tr = boost::make_shared<Maca::TextReader>(boost::ref(input_stream), sa, 1);

				if (split_chunks) {
					while (boost::shared_ptr<Corpus2::Chunk> chunk = tr->get_next_chunk()) {
						if (!chunk->empty())writer->write_chunk(*chunk);
					}
				} else {
					while (Corpus2::Sentence::Ptr sentence = tr->get_next_sentence()) {
						writer->write_sentence(*sentence);
					}
				}
			}

			std::string res = out_stream.str();
			out_stream.str("");
			return res;
	} else {
		throw std::invalid_argument("Specify maca config");
	}
}
