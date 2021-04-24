target_include_directories(neoimp PUBLIC
                           .
                          )

target_sources(neoimp PUBLIC
               PNGImageMapper.cpp
               ImageMapperFactory.cpp
               Component.cpp
              )

target_link_libraries(neoimp png)
