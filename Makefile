SOURCE = game-of-life
TARGET = game-of-life

CXXFLAGS = -O2 -Wall
LDFLAGS =

build: $(TARGET)
$(TARGET): $(SOURCE).o
	$(CXX) $(LDFLAGS)   $^ -o $@
%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f $(SOURCE) *.a *.o
	rm -f $(TARGET) *~