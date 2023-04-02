#ifndef webrtc_base_TYPES_HPP
#define webrtc_base_TYPES_HPP

#include <string>

namespace webrtc_base {
    /** Different types of signalling messages */
    enum SignallingMessageType {
        SIGNALLING_NEW_PEER,          //! a new peer has connected
        SIGNALLING_PEER_DISCONNECT,   //! a peer is disconnecting itself
        SIGNALLING_PEER_DISCONNECTED, //! a peer has been disconnected
        SIGNALLING_REQUEST_OFFER,     //! a polite peer is requesting an offer
        SIGNALLING_OFFER,             //! offer from a peer
        SIGNALLING_ANSWER,            //! answer from a peer
        SIGNALLING_ICE_CANDIDATE      //! ICE negotiation message
    };

    /** A message from the signalling protocol */
    struct SignallingMessage {
        std::string from;
        std::string to;
        SignallingMessageType type;
        std::string message;
        /** m-line index in case type is ICE_CANDIDATE */
        unsigned int m_line = 0;
    };
}

#endif
