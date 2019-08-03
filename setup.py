from setuptools import Extension, setup
import subprocess


maca_analyse = Extension(
	name='_maca_analyse',
	sources=['maca_analyse.cpp',
			'maca_analyse.i'
	],
	library_dirs=['/usr/local/lib', '/usr/lib'],
	swig_opts=['-c++'],
	libraries=['boost_program_options', 'icuuc', 'pwrutils', 'toki', 'corpus2', 'maca'],
)

setup(
	name='maca_analyse',
	version='0.1.0',
	author='Zhylkaaa',
	description='Python wrapper for maca-analyse',
	url='https://github.com/Zhylkaaa/maca_analyse',
	download_url='https://github.com/Zhylkaaa/maca_analyse',
	ext_modules=[maca_analyse],
	py_modules=['maca_analyse']
)