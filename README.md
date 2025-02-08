# colorex-c

`colorex-c` is a simple and flexible C library that provides an easy way to style your terminal output with color and text formatting. With support for both RGB and HEX color codes, as well as text styles like bold, italic, underline, strikethrough, and more, it makes your terminal applications visually more appealing and readable.

## Features
* RGB Color Support: Define colors using RGB values (e.g., color_rgb(255, 0, 0)).
* HEX Color Support: Use HEX color codes (e.g., color_hex("#FF0000")).
* Text Styles: Bold, italic, underline, strikethrough, dim, and inverted text.
* Background Colors: Set the background color using RGB or HEX.
* Chainable API: Apply multiple styles in a single statement using method chaining.

```c++
#include <stdio.h>
#include "colorize.h"

int main() {

    // Basic color usage
    const char* rgb = "Hello, World!";
    char* rgb_text = apply_color(rgb, "0,255,0");
    printf("%s\n", rgb_text);
    free(rgb_text);

    const char* hex = "Error";
    char* hex_text = apply_color(hex, "#FF0000");
    printf("%s\n", hex_text);
    free(hex_text);

    // Text styles
    const char* bold = "Bold Text";
    char* bold_text = apply_bold(bold);
    printf("%s\n", bold_text);
    free(bold_text);

    const char* italic = "Italic Text";
    char* italic_text = apply_italic(italic);
    printf("%s\n", italic_text);
    free(italic_text);

    const char* underlined = "Underlined Text";
    char* underlined_text = apply_underline(underlined);
    printf("%s\n", underlined_text);
    free(underlined_text);

    const char* strikethrough = "Strikethrough Text";
    char* strikethrough_text = apply_strikethrough(strikethrough);
    printf("%s\n", strikethrough_text);
    free(strikethrough_text);

    const char* dim = "Dim Text";
    char* dim_text = apply_dim(dim);
    printf("%s\n", dim_text);
    free(dim_text);

    const char* inverted = "Inverted Text";
    char* inverted_text = apply_invert(inverted);
    printf("%s\n", inverted_text);
    free(inverted_text);

    // Background color
    const char* background = "Background Color";
    char* background_text = apply_bg_color(background, "0,0,255");
    printf("%s\n", background_text);
    free(background_text);

    const char* all = "ALL";
    char* all_text = apply_color(all, "0,255,0");
    all_text = apply_bold(all_text);
    all_text = apply_italic(all_text);
    all_text = apply_underline(all_text);
    all_text = apply_strikethrough(all_text);
    all_text = apply_dim(all_text);
    all_text = apply_invert(all_text);
    all_text = apply_bg_color(all_text, "0,0,255");
    printf("%s", all_text);
    free(all_text);

    return 0;
}
```

## Supported Styles

* Color: RGB and HEX color formats.
* Text Styles:
    * bold()
    * italic()
    * underline()
    * strikethrough()
    * dim()
    * invert()
* Background Colors: bg_color() with RGB or HEX values.

## Example Output
The following example would result in a green-colored "Hello, World!" and a red "Error!" message in the terminal.

```rust
const char* rgb = "Hello, World!";          // Green text
char* rgb_text = apply_color(rgb, "0,255,0");
printf("%s\n", rgb_text);
free(rgb_text);

const char* hex = "Error";                  // Red text
char* hex_text = apply_color(hex, "#FF0000");
printf("%s\n", hex_text);
free(hex_text);   
```

## Supported Color Formats
* RGB: `"r,g,b"` (e.g., `"255,0,0"` for red).
* HEX: `"#RRGGBB"` (e.g., `"#FF0000"` for red).

# License
This project is licensed under the MPL-2.0 License - see the [LICENSE](LICENSE) file for details.