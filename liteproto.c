/*
 * lightweighted protobuf encoding and decoding library for Python
 */
#include <Python.h>


static PyObject *
liteproto_load(PyObject *self, PyObject *args) {
    return Py_None;
}


static PyMethodDef LiteprotoMethods[] = {
    {"load", liteproto_load, METH_VARARGS, "load a proto file"},
    {NULL, NULL, 0, NULL}
};


PyMODINIT_FUNC
initliteproto(void) {
    (void) Py_InitModule("liteproto", LiteprotoMethods);
}

