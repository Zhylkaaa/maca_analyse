#include "maca_analyse.h"

std::string maca_analyse(std::string config, std::string toki_config_path, std::string input_text) {
	std::string input_format = "txt", output_format = "plain";

	Toki::Path::Instance().set_verbose(false);
	Maca::Path::Instance().set_verbose(false);
	Corpus2::Path::Instance().set_verbose(false);

	if (!toki_config_path.empty()) {
		Toki::Path::Instance().set_search_path(toki_config_path);
    }

	if (!config.empty()) {
		try {
			static boost::shared_ptr<Maca::SentenceAnalyser> sa = Maca::SentenceAnalyser::create_from_named_config(config);

			static std::stringstream out_stream;
			static boost::shared_ptr<Corpus2::TokenWriter> writer = Corpus2::TokenWriter::create_stream_writer(output_format, out_stream, sa->tagset());

			std::stringstream input_stream(input_text);
			std::string line;

			while (std::getline(input_stream, line)) {
				sa->set_input_source(UnicodeString::fromUTF8(line));
				while (Corpus2::Sentence::Ptr sentence = sa->get_next_sentence()) {
					writer->write_sentence(*sentence);
				}
			}
			std::string res = out_stream.str();
			out_stream.str("");
			return res;
		} catch (Maca::MacaError& e) {
			std::cerr << "Maca Error: " << e.info() << "\n";
			exit(4);
		} catch (Toki::TokiError& e) {
			std::cerr << "Tokenizer Error: " << e.info() << "\n";
			exit(6);
		} catch (Corpus2::Corpus2Error& e) {
			std::cerr << "Corpus2 Error: " << e.info() << "\n";
			exit(8);
		}
	} else {
		std::cerr << "Specify config\n";
		exit(1);
	}
}