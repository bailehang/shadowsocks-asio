#pragma once

#include <boost/asio.hpp>

#include <shadowsocks/cipher/detail/cipher_context.h>
#include <shadowsocks/cipher/detail/read_op.h>
#include <shadowsocks/cipher/detail/write_op.h>

namespace shadowsocks
{

template <typename Datagram>
class datagram
{
public:
    typedef typename Datagram::endpoint_type endpoint_type;
    
    template<typename Arg>
    datagram(Arg && arg, const cipher_info & info, const std::vector<uint8_t> & key)
        : next_layer_(std::move(arg))
        , context_(std::make_unique<detail::cipher_context>(info, key))
    {
    }
    
    datagram(datagram && other)
        : next_layer_(std::move(other.next_layer_))
        , context_(std::move(other.context_))
    {
    }
    
    datagram & operator=(datagram && other)
    {
        next_layer_ = std::move(other.next_layer_);
        context_ = std::move(other.context_);
        return *this;
    }

    Datagram & next_layer()
    {
        return  next_layer_;
    }
    
    template <typename ConstBufferSequence, typename WriteHandler>
    BOOST_ASIO_INITFN_RESULT_TYPE(WriteHandler,
        void (boost::system::error_code, std::size_t))
    async_send(const ConstBufferSequence& buffers,
        BOOST_ASIO_MOVE_ARG(WriteHandler) handler)
    {
      // If you get an error on the following line it means that your handler does
      // not meet the documented type requirements for a WriteHandler.
      BOOST_ASIO_WRITE_HANDLER_CHECK(WriteHandler, handler) type_check;
    
      boost::asio::async_completion<WriteHandler,
        void (boost::system::error_code, std::size_t)> init(handler);
    
      return init.result.get();
    }
    
    template <typename ConstBufferSequence, typename WriteHandler>
    BOOST_ASIO_INITFN_RESULT_TYPE(WriteHandler,
        void (boost::system::error_code, std::size_t))
    async_send(const ConstBufferSequence& buffers,
        boost::asio::socket_base::message_flags flags,
        BOOST_ASIO_MOVE_ARG(WriteHandler) handler)
    {
      // If you get an error on the following line it means that your handler does
      // not meet the documented type requirements for a WriteHandler.
      BOOST_ASIO_WRITE_HANDLER_CHECK(WriteHandler, handler) type_check;
    
      boost::asio::async_completion<WriteHandler,
        void (boost::system::error_code, std::size_t)> init(handler);
    
      return init.result.get();
    }
  
    template <typename ConstBufferSequence, typename WriteHandler>
    BOOST_ASIO_INITFN_RESULT_TYPE(WriteHandler,
        void (boost::system::error_code, std::size_t))
    async_send_to(const ConstBufferSequence& buffers,
        const endpoint_type& destination,
        BOOST_ASIO_MOVE_ARG(WriteHandler) handler)
    {
      // If you get an error on the following line it means that your handler does
      // not meet the documented type requirements for a WriteHandler.
      BOOST_ASIO_WRITE_HANDLER_CHECK(WriteHandler, handler) type_check;
    
      boost::asio::async_completion<WriteHandler,
        void (boost::system::error_code, std::size_t)> init(handler);
    
      return init.result.get();
    }
  
    template <typename ConstBufferSequence, typename WriteHandler>
    BOOST_ASIO_INITFN_RESULT_TYPE(WriteHandler,
        void (boost::system::error_code, std::size_t))
    async_send_to(const ConstBufferSequence& buffers,
        const endpoint_type& destination, boost::asio::socket_base::message_flags flags,
        BOOST_ASIO_MOVE_ARG(WriteHandler) handler)
    {
      // If you get an error on the following line it means that your handler does
      // not meet the documented type requirements for a WriteHandler.
      BOOST_ASIO_WRITE_HANDLER_CHECK(WriteHandler, handler) type_check;
    
      boost::asio::async_completion<WriteHandler,
        void (boost::system::error_code, std::size_t)> init(handler);
    
      return init.result.get();
    }
  
    template <typename MutableBufferSequence, typename ReadHandler>
    BOOST_ASIO_INITFN_RESULT_TYPE(ReadHandler,
        void (boost::system::error_code, std::size_t))
    async_receive(const MutableBufferSequence& buffers,
        BOOST_ASIO_MOVE_ARG(ReadHandler) handler)
    {
      // If you get an error on the following line it means that your handler does
      // not meet the documented type requirements for a ReadHandler.
      BOOST_ASIO_READ_HANDLER_CHECK(ReadHandler, handler) type_check;
    
      boost::asio::async_completion<ReadHandler,
        void (boost::system::error_code, std::size_t)> init(handler);
    
      return init.result.get();
    }
    
    template <typename MutableBufferSequence, typename ReadHandler>
    BOOST_ASIO_INITFN_RESULT_TYPE(ReadHandler,
        void (boost::system::error_code, std::size_t))
    async_receive(const MutableBufferSequence& buffers,
        boost::asio::socket_base::message_flags flags,
        BOOST_ASIO_MOVE_ARG(ReadHandler) handler)
    {
      // If you get an error on the following line it means that your handler does
      // not meet the documented type requirements for a ReadHandler.
      BOOST_ASIO_READ_HANDLER_CHECK(ReadHandler, handler) type_check;
    
      boost::asio::async_completion<ReadHandler,
        void (boost::system::error_code, std::size_t)> init(handler);
    
      return init.result.get();
    }
  
    template <typename MutableBufferSequence, typename ReadHandler>
    BOOST_ASIO_INITFN_RESULT_TYPE(ReadHandler,
        void (boost::system::error_code, std::size_t))
    async_receive_from(const MutableBufferSequence& buffers,
        endpoint_type& sender_endpoint,
        BOOST_ASIO_MOVE_ARG(ReadHandler) handler)
    {
      // If you get an error on the following line it means that your handler does
      // not meet the documented type requirements for a ReadHandler.
      BOOST_ASIO_READ_HANDLER_CHECK(ReadHandler, handler) type_check;
    
      boost::asio::async_completion<ReadHandler,
        void (boost::system::error_code, std::size_t)> init(handler);
    
      return init.result.get();
    }
  
    template <typename MutableBufferSequence, typename ReadHandler>
    BOOST_ASIO_INITFN_RESULT_TYPE(ReadHandler,
        void (boost::system::error_code, std::size_t))
    async_receive_from(const MutableBufferSequence& buffers,
        endpoint_type& sender_endpoint, boost::asio::socket_base::message_flags flags,
        BOOST_ASIO_MOVE_ARG(ReadHandler) handler)
    {
      // If you get an error on the following line it means that your handler does
      // not meet the documented type requirements for a ReadHandler.
      BOOST_ASIO_READ_HANDLER_CHECK(ReadHandler, handler) type_check;
    
      boost::asio::async_completion<ReadHandler,
        void (boost::system::error_code, std::size_t)> init(handler);
    
      return init.result.get();
    }

private:
    Datagram next_layer_;

    std::unique_ptr<detail::cipher_context> context_;
};

}
