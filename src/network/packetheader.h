#ifndef FORGE_PACKET_HEADER_H
#define FORGE_PACKET_HEADER_H

struct PacketHeader
{
public:
    static PacketHeader unserialize( const QByteArray& datagram );

    size_t headerSize() const;

private:
};

#endif
