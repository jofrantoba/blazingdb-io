/*
 * BlazingContext.cpp
 *
 *  Created on: Dec 5, 2017
 *      Author: felipe
 */

#include <aws/core/Aws.h>

#include "Config/BlazingContext.h"
#include "Util/StringUtil.h"
#include "Util/FileUtil.h"
#include "arrow/status.h"
#include "Library/Logging/Logger.h"
namespace Logging = Library::Logging;

BlazingContext* BlazingContext::instance = nullptr;

void BlazingContext::initExternalSystems() {
	Aws::SDKOptions sdkOptions;
	Aws::InitAPI(sdkOptions);
}

void BlazingContext::shutDownExternalSystems() {
	Aws::SDKOptions sdkOptions;
	Aws::ShutdownAPI(sdkOptions);
}

BlazingContext::BlazingContext()
:  fileSystemManager(new FileSystemManager()){

}

BlazingContext::~BlazingContext() {
	if(instance != nullptr){
		delete instance;
	}

}


std::shared_ptr<FileSystemManager> BlazingContext::getFileSystemManager(){
	return this->fileSystemManager;
}



BlazingContext * BlazingContext::getInstance(){
	if(instance == NULL){
		instance = new BlazingContext();
	}
	return instance;
}


