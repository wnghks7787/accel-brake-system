CXX = g++
CXXFLAGS = -Wall -g -Iinclude
LDFLAGS = -l wiringPi

SRCDIR = src
BUILDDIR = build

TARGET = accel-brake-system
SRCS = $(SRCDIR)/main.cpp $(SRCDIR)/vehicle.cpp
OBJS = $(SRCS:$(SRCDIR)/%.cpp=$(BUILDDIR)/%.o)

all:$(TARGET)

$(TARGET): $(OBJS)
	$(CXX) -o $@ $^ $(LDFLAGS)

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	mkdir -p $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILDDIR) $(TARGET)