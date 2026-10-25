CXX = g++
CXXFLAGS = -std=c++17 -Wall
LIBS = -lsfml-graphics -lsfml-window -lsfml-system
TARGET = optics_sim
SRCS = main.cpp PhysicsEngine.cpp NoiseGenerator.cpp Visualizer.cpp InputHandler.cpp Overlay.cpp

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET) $(LIBS)

clean:
	rm -f $(TARGET)
