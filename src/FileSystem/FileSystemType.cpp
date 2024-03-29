/*
 * Copyright 2017 BlazingDB, Inc.
 *     Copyright 2018 Percy Camilo Triveño Aucahuasi <percy@blazingdb.com>
 */

#include "FileSystemType.h"

const std::string fileSystemTypeName(FileSystemType fileSystemType) {
	switch (fileSystemType) {
		case FileSystemType::LOCAL: return "LOCAL"; break;
		case FileSystemType::HDFS: return "HDFS"; break;
		case FileSystemType::S3: return "S3"; break;
		case FileSystemType::NFS4: return "NFS4"; break;
	}

	return "UNDEFINED";
}

const std::string fileTypeName(FileType fileType) {
	switch (fileType) {
		case FileType::FILE: return "FILE"; break;
		case FileType::DIRECTORY: return "DIRECTORY"; break;
	}

	return "UNDEFINED";
}
