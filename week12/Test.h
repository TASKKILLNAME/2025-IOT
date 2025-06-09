typedef nx_struct test_data_msg {
    nx_am_addr_t srcID;
    nx_uint32_t seqNo;
    nx_uint16_t type;
    nx_uint16_t Temp;
    nx_uint16_t Humi;
    nx_uint16_t Illu;
    nx_uint16_t battery;
} test_data_msg_t;
