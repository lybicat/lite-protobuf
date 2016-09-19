from unittest import TestCase
from liteproto import load
from liteproto import loads


class TestLiteProto(TestCase):
    def test_load_proto_file(self):
        load('./ut.proto')

    def test_load_proto_string(self):
        loads('''syntax = "proto2";

message Ack{
    enum ConfirmationStatus{
        ACK = 1;
        NACK = 2;
    }

    required ConfirmationStatus confirmation = 1;
    required uint32 transactionId = 2;
    optional string reason = 3;
}''')

