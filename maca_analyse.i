%module maca_analyse
%{
        #include "maca_analyse.h"
%}

%exception {
        try{
                $action
        } catch (Maca::MacaError& e){
                PyErr_SetString(PyExc_RuntimeError, e.info().c_str());
                SWIG_fail;
        } catch (Toki::TokiError& e){
                PyErr_SetString(PyExc_RuntimeError, e.info().c_str());
                SWIG_fail;
        } catch (Corpus2::Corpus2Error& e){
                PyErr_SetString(PyExc_RuntimeError, e.info().c_str());
                SWIG_fail;        
        } catch (std::invalid_argument& e){
                PyErr_SetString(PyExc_RuntimeError, e.what());
                SWIG_fail;
        }
}

%include "std_string.i"
%include "maca_analyse.h"

