#include "Library/Logging/CoutOutput.h"
#include "Library/Logging/Logger.h"
#include <iostream>

namespace Library {
    namespace Logging {
        CoutOutput::CoutOutput() {
        }

        CoutOutput::~CoutOutput() {
        }

        void CoutOutput::flush(std::string&& log) {
            std::unique_lock<std::mutex> lock(mutex);
            std::cout << log << std::endl;
        }

        void CoutOutput::flush(const std::string& log) {
            std::unique_lock<std::mutex> lock(mutex);
            std::cout << log << std::endl;
        }

        void CoutOutput::setNodeIdentifier(const unsigned int nodeInd){
        	Logging::Logger().logInfo("Node index is " + std::to_string(nodeInd));
        }
    }
}
