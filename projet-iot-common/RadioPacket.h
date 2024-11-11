#pragma once
#include "MicroBit.h"
//#include <openssl/aes.h>

class RadioPacket{
    public: 
        RadioPacket();
        RadioPacket(PacketBuffer p, uint16_t idserv);
        ~RadioPacket();
        int getErrorCode();
        ManagedString getError();

        // Getters
        uint8_t getOpCode();
        uint16_t getSource();
        uint16_t getDest();
        uint8_t *getData();
        PacketBuffer getPacketBuffer();
        uint16_t getDataSize();

        //setters
        void setOpCode(uint8_t opcode);
        void setSource(uint16_t source);
        void setDest(uint16_t dest);
        void setData(uint8_t *src, int size);

        bool isBroadcast();

        //encryption, Decryption
        void encrypt();
        void decrypt();
    
    private:
        void setErrorCode(int code);
        bool broadcast;
        int bufferSize;
        uint16_t idServ;
        uint8_t opcode;
        uint16_t idSource;
        uint16_t idDest;
        uint16_t dataSize;
        uint8_t *data;
        uint16_t* checksum;
        int errornb;
};