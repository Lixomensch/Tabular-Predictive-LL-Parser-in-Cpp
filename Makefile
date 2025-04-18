CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

SRC_DIR = src
BUILD_DIR = build
TESTS_OUTPUT_DIR = tests/output

SRC = $(wildcard $(SRC_DIR)/*.cpp)
OBJ = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRC))

TARGET = parser

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $(TARGET)

run:
	python3 tests/test_parser.py

clear:
	@find $(BUILD_DIR) -mindepth 1 ! -name ".gitkeep" -delete
	@find $(TESTS_OUTPUT_DIR) -mindepth 1 ! -name ".gitkeep" -delete
	@rm -f parser