#ifndef webrtc_base_TYPES_HPP
#define webrtc_base_TYPES_HPP

#include <string>

namespace webrtc_base {
    /** Different types of signalling messages */
    enum SignallingMessageType {
        SIGNALLING_PEER_DISCONNECT,   //! a peer is disconnecting itself
        SIGNALLING_PEER_DISCONNECTED, //! a peer has been disconnected
        SIGNALLING_REQUEST_OFFER,     //! a polite peer is requesting an offer
        SIGNALLING_OFFER,             //! offer from a peer
        SIGNALLING_ANSWER,            //! answer from a peer
        SIGNALLING_ICE_CANDIDATE      //! ICE negotiation message
    };

    /** A message from the signalling protocol */
    struct SignallingMessage {
        /** The ID of the peer that generated the message */
        std::string from;
        /** The ID of the peer for which this message is intended, or empty for broadcast
         */
        std::string to;

        /** Kind of message */
        SignallingMessageType type;

        /** Message contents
         *
         * In the case of OFFER and ANSWER, this is the SDP description as
         * string. in ICE_CANDIDATE, the ICE candidate line. REQUEST_OFFER and
         * DISCONNECT leave this field empty. DISCONNECTED contains the peer ID
         * of the disconnected peer
         */
        std::string message;
        /** m-line index in case type is ICE_CANDIDATE */
        unsigned int m_line = 0;
    };
}

#endif
