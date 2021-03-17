# Gold++

List of Rich Libraries in gold library:

1. I/O, formatting, and rich manipulators
2. Windows GUI easy access (win32 api and gdi)
3. Console features
4. Console canvas
5. Utilities (ranges, omnibox, pattern matching, ...)
6. Math functions, number class
7. String functions, string class
8. Algorithms
9. XML and JSON Parser

## Console Canvas
Sypnosis:
```c++
namespace console::canvas {
  enum mode : char {
    fill = 'f', outline = 'o';   
  };
  struct coord {
    int x, y;
  }; 
  
  void basic_rectangle(int x, int y, int width, int height, int color, mode mod); 
  void basic_square(int x, int y, int length, int color, mode mod);
  void basic_ellipse(int x, int y, int a, int b, int color, mode mod);
  void basic_circle(int x, int y, int r, int color, mode mod);
  
  void basic_line(int x1, int y1, int x2, int y2, int color);
  void basic_arc(int x, int y, int r, double s1, double s2, int color);
  
  template <typename T, typename... Ts>
  void basic_line_path(std::pair<T, T> coord, Ts... coords);
  
}
```
