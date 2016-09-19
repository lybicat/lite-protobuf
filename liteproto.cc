/*
 * lightweighted protobuf encoding and decoding library for Python
 */
#include <Python.h>
#include <google/protobuf/compiler/importer.h>


static PyObject *
liteproto_load(PyObject *self, PyObject *file_path) {
    return Py_None;
}


static PyObject *
liteproto_loads(PyObject *self, PyObject *proto_str) {
    return Py_None;
}


static PyMethodDef LiteprotoMethods[] = {
    {"load", liteproto_load, METH_VARARGS, "load a proto file"},
    {"loads", liteproto_loads, METH_VARARGS, "load from a proto string"},
    {NULL, NULL, 0, NULL}
};


PyMODINIT_FUNC
initliteproto(void) {
    (void) Py_InitModule("liteproto", LiteprotoMethods);
}

