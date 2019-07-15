#include <libcorpus2/io/writer.h>
#include <libmaca/util/sentenceanalyser.h>
#include <libtoki/util/settings.h>

#include <boost/algorithm/string.hpp>
#include <boost/make_shared.hpp>

#include <fstream>

std::string maca_analyse(std::string config, std::string toki_config, std::string input_text);