#include <libcorpus2/io/writer.h>
#include <libmaca/io/text.h>
#include <libmaca/io/premorph.h>
#include <libmaca/morph/dispatchanalyser.h>
#include <libmaca/util/settings.h>
#include <libcorpus2/util/settings.h>
#include <libmaca/util/sentenceanalyser.h>
#include <libcorpus2/util/tokentimer.h>

#include <libmaca/version.h>

#include <libtoki/sentencesplitter.h>
#include <libtoki/tokenizer/layertokenizer.h>
#include <boost/foreach.hpp>
#include <libtoki/util/settings.h>

#include <boost/algorithm/string.hpp>
#include <boost/program_options.hpp>
#include <boost/make_shared.hpp>

#include <fstream>
#include <omp.h>

std::string maca_analyse(std::string config, std::string toki_config, std::string input_text);