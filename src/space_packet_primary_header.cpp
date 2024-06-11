#include "space_packet_primary_header.h"
#include <iostream>
#include <bitset>

// Implementation class
class space_packet_primary_header_impl {
public:
    // Packet Primary Header fields
    unsigned char version_number : 3; // 3 bits
    unsigned char packet_type : 1; // 1 bit
    unsigned char secondary_header_flag : 1; // 1 bit
    unsigned short apid : 11; // 11 bits
    unsigned char sequence_flags : 2; // 2 bits
    unsigned short packet_sequence_count : 14; // 14 bits
    unsigned short packet_data_length : 16; // 16 bits

    space_packet_primary_header_impl() {
        version_number = 0; // 000 in binary
        packet_type = 0;
        secondary_header_flag = 0;
        apid = 0;
        sequence_flags = 0;
        packet_sequence_count = 0;
        packet_data_length = 0;
    }

    void display_header() const {
        std::cout << "Space Packet Primary Header:" << std::endl;
        std::cout << "Version Number: " << std::bitset<3>(version_number) << std::endl;
        std::cout << "Packet Type: " << std::bitset<1>(packet_type) << std::endl;
        std::cout << "Secondary Header Flag: " << std::bitset<1>(secondary_header_flag) << std::endl;
        std::cout << "APID: " << std::bitset<11>(apid) << std::endl;
        std::cout << "Sequence Flags: " << std::bitset<2>(sequence_flags) << std::endl;
        std::cout << "Packet Sequence Count: " << std::bitset<14>(packet_sequence_count) << std::endl;
        std::cout << "Packet Data Length: " << std::bitset<16>(packet_data_length) << std::endl;
    }

    void set_header(unsigned char version, unsigned char type, unsigned char sec_hdr_flag,
                    unsigned short app_id, unsigned char seq_flags, unsigned short seq_count,
                    unsigned short data_length) {
        version_number = version;
        packet_type = type;
        secondary_header_flag = sec_hdr_flag;
        apid = app_id;
        sequence_flags = seq_flags;
        packet_sequence_count = seq_count;
        packet_data_length = data_length;
    }
};

space_packet_primary_header::space_packet_primary_header() : p_impl(new space_packet_primary_header_impl()) {}

space_packet_primary_header::~space_packet_primary_header() {
    delete p_impl;
}

void space_packet_primary_header::display_header() const {
    p_impl->display_header();
}

void space_packet_primary_header::set_header(unsigned char version, unsigned char type, unsigned char sec_hdr_flag,
                                             unsigned short app_id, unsigned char seq_flags, unsigned short seq_count,
                                             unsigned short data_length) {
    p_impl->set_header(version, type, sec_hdr_flag, app_id, seq_flags, seq_count, data_length);
}

