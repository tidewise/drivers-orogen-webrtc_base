# Common Types and Functionality for WebRTC communication

This package intends to provide common types, signalling protocol definition
and functionality needed to use WebRTC as a way to interact with a Rock system.

The main purpose of the package is to standardize signalling. WebRTC components
in Rock should be indepdenent of the signalling mechanism, mostly forwarding
WebRTC's signalling standard messages on ports so that they can be transmitted
through a system designer's

WebRTC peer components should provide an input and an output port of type
SignallingMessage. Signalling components will then provide the interface with
an actual signalling server (or may implement their own).
webrtc_base::RustySignallingTask may be used as an example based on the very
simple rustysignal signalling server.

## Protocol

- The negotiation protocol is designed around the "perfect negotiation" concept
  (https://developer.mozilla.org/en-US/docs/Web/API/WebRTC_API/Perfect_negotiation)
- Peers are identified by an arbitrary string, that is specific to the actual
  signalling.
- Peer components MUST fill the `from` field of the `SignallingMessage`
- Messages with an empty `to` field are meant as broadcasts (if the signalling
  server supports it)
- Peer components MAY send a PEER_DISCONNECT message. They MAY receive a
  PEER_DISCONNECTED message in acknowledgment if they do so.
- The OFFER, ANSWER and ICE_CANDIDATE messages transport standard WebRTC data.
- A polite peer MUST periodically send a REQUEST_OFFER message to its intended
  peer if it has one configured and if it has not yet received an offer. The
  periodicity is meant to alleviate asynchronicity in connection (e.g. who connects
  first)
- An impolite peer MUST periodically send an OFFER message to its intended
  peer if it has one configured and if it has not yet received an answer. The
  periodicity is meant to alleviate asynchronicity in connection (e.g. who connects
  first)