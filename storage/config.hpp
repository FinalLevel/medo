#pragma once
#ifndef __FL_METIS_CONFIG_HPP
#define	__FL_METIS_CONFIG_HPP

///////////////////////////////////////////////////////////////////////////////
//
// Copyright Denys Misko <gdraal@gmail.com>, Final Level, 2014.
// Distributed under BSD (3-Clause) License (See
// accompanying file LICENSE)
//
// Description: Metis server's storage configuration class
///////////////////////////////////////////////////////////////////////////////

#include <boost/property_tree/ptree.hpp>

#include <string>
#include <vector>
#include "socket.hpp"
#include "../types.hpp"

namespace fl {
	namespace metis {
		using fl::network::Socket;

		const char * const DEFAULT_CONFIG = SYSCONFDIR "/metis.cnf";
		const size_t MAX_BUF_SIZE = 300000;
		
		const int DEFAULT_SOCKET_TIMEOUT = 60;
		const size_t DEFAULT_SOCKET_QUEUE_LENGTH = 10000;
		const size_t EPOLL_WORKER_STACK_SIZE = 100000;
		const size_t DEFAULT_WORKERS_COUNT = 2;
		
		const size_t DEFAULT_BUFFER_SIZE = 32000;
		const size_t DEFAULT_MAX_FREE_BUFFERS = 500;
		
		
		
		const uint32_t DEFAULT_CMD_PORT = 7008;
		
		class Config
		{
		public:
			Config(int argc, char *argv[]);
			const TServerID serverID() const
			{
				return _serverID;
			}
			const std::string &dataPath() const
			{
				return _dataPath;
			}
			
			const std::string &logPath() const
			{
				return _logPath;
			}
			int logLevel() const
			{
				return _logLevel;
			}
			typedef uint32_t TStatus;
			static const TStatus ST_LOG_STDOUT = 0x1;
			const bool isLogStdout() const
			{
				return _status & ST_LOG_STDOUT;
			}
			const int cmdTimeout() const
			{
				return _cmdTimeout;
			}
			
			const size_t workerQueueLength() const
			{
				return _workerQueueLength;
			}
			const size_t workers() const
			{
				return _workers;
			}
			const size_t bufferSize() const
			{
				return _bufferSize;
			}
			const size_t maxFreeBuffers() const
			{
				return _maxFreeBuffers;
			}
		private:
			void _parseNetworkParams(boost::property_tree::ptree &pt);
			TServerID _serverID;
			TStatus _status;
			std::string _logPath;
			int _logLevel;
			
			std::string _dataPath;
			
			int _cmdTimeout;
			size_t _workerQueueLength;
			size_t _workers;
			
			size_t _bufferSize;
			size_t _maxFreeBuffers;
			
			std::string _listenIp;
			uint32_t _port;

		};
	}
}

#endif // __FL_METIS_CONFIG_HPP