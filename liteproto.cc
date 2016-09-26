/*
 * lightweighted protobuf encoding and decoding library for Python
 */
#include <Python.h>
#include <iostream>
#include <google/protobuf/compiler/importer.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/descriptor.pb.h>
#include <google/protobuf/dynamic_message.h>

using namespace std;
using namespace google::protobuf;
using namespace google::protobuf::compiler;


/*
static PyObject *
liteproto_load(PyObject *self, PyObject *args)
{
    const char *command;
    int sts;

    if (!PyArg_ParseTuple(args, "s", &command))
        return NULL;
    sts = system(command);
    return Py_BuildValue("i", sts);
}*/

static PyObject *
liteproto_load(PyObject *self, PyObject *args) {
    const char *filePath;
    const char *msgType;
    DiskSourceTree sourceTree;
    //look up .proto file in current directory
    sourceTree.MapPath("", "./");
    Importer importer(&sourceTree, NULL);
    //runtime compile foo.proto
    if (!PyArg_ParseTuple(args, "ss", &filePath, &msgType)) {
        return NULL;
    }
    importer.Import(filePath);

    const Descriptor *descriptor = importer.pool()->FindMessageTypeByName(msgType);
    //cout << descriptor->DebugString();

    // build a dynamic message by "Pair" proto
    DynamicMessageFactory factory;
    const Message *message = factory.GetPrototype(descriptor);
    // create a real instance of "Pair"
    //Message *pair = message->New();

    //// write the "Pair" instance by reflection
    //const Reflection *reflection = pair->GetReflection();

    //const FieldDescriptor *field = NULL;
    //field = descriptor->FindFieldByName("key");
    //reflection->SetString(pair, field, "my key");
    //field = descriptor->FindFieldByName("value");
    //reflection->SetUInt32(pair, field, 1111);

    //cout << pair->DebugString();

    //delete pair;
    //return Py_BuildValue("O", message);
    Py_INCREF(Py_None);
    return Py_None;
}


static PyObject *
liteproto_loads(PyObject *self, PyObject *proto_str) {
    // TODO
    // 1. Inherit from SourceTree, and reuse the code of Importer
    char *loads_str = "loads";
    return Py_BuildValue("s", loads_str);
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

