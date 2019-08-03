# Maca Analyse 

It's small tool that extends [maca-analyse original tool](http://nlp.pwr.wroc.pl/maca.git) to return String object to Python 3. 

## Usage 

maca_analyse returns String object to Python created by MacaAnalyser

And it's pretty easy to use:

``` Python3
from maca_analyse import maca_analyse

....some code....

analysed_text = maca_analyse("config name", "path to toki config or leave blank", 
											"text you want to analyse") # returns string object

....some code....
```

Check [maca documentation](http://nlp.pwr.wroc.pl/redmine/projects/libpltagger/wiki)

## Installation

To install maca_analyse you should have **Boost**, **Toki**, **Maca**, **Corpus2** and **PwrUtils** libraries installed.

This will install packages to your /usr/local/lib/pythonx.x/dist-packages/

``` bash
$ git clone https://github.com/Zhylkaaa/maca_analyse
$ cd maca_analyse
$ ./build_maca_analyse_wrapper.sh
```

Now you can remove `maca_analyse/` folder.

**Note:**
`sudo` is important, because build script copy generated with [SWIG](http://www.swig.org) python package to /usr/local/lib/pythonx.x/dist-packages/, if you don’t want to do so, you can comment 2 last lines in build script, or change instalation path.

## Supported systems:

Currently this tool works only for Linux. 

## Tested build configurations:

- Ubuntu 18.04 and Python 3.6.8

