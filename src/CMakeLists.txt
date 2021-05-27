cmake_minimum_required(VERSION 3.18.2)
project(lets-trade-test)

find_package(Boost 1.68.0)

#add_subdirectory(<MORE FOLDERS>)
set(SOURCE_FILES main.cpp)

add_executable(lets-trade ${SOURCE_FILES}
	stock.cpp
	stock.hpp
	banking.cpp
	banking.hpp
	csvExtractor.cpp
	csvExtractor.hpp
	player.cpp
	player.hpp
	Portfolio.cpp
	Portfolio.hpp
	transaction.cpp
	transaction.hpp
	share.cpp
	share.hpp
)
