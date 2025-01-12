CXX = g++
CXXFLAGS = -O2 -fPIC -Wall -Wextra

INCLUDES = -I$(HLSDK)/metamod -I$(HLSDK)/common -I$(HLSDK)/engine -I$(HLSDK)/dlls -I$(HLSDK)/pm_shared
LDFLAGS = -shared

SRCS = plugin.cpp
OBJS = $(SRCS:.cpp=.o)

TARGET = your_plugin_mm_i386.so

all: $(TARGET)

$(TARGET): $(OBJS)
    $(CXX) $(LDFLAGS) -o $@ $^

%.o: %.cpp
    $(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
    rm -f $(OBJS) $(TARGET)
