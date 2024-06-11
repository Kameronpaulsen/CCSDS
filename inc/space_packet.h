#ifndef SPACE_PACKET_PRIMARY_HEADER_H
#define SPACE_PACKET_PRIMARY_HEADER_H

class SpacePacketPrimaryHeaderImpl;

class SpacePacketPrimaryHeader {
public:
    SpacePacketPrimaryHeader();
    ~SpacePacketPrimaryHeader();

    void displayHeader() const;
    void setHeader(unsigned char version, unsigned char type, unsigned char secHdrFlag,
                   unsigned short appId, unsigned char seqFlags, unsigned short seqCount,
                   unsigned short dataLength);

private:
    SpacePacketPrimaryHeaderImpl* pImpl;
};

#endif // SPACE_PACKET_PRIMARY_HEADER_H

