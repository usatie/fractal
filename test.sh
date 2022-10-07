#!/bin/bash
# Invalid Arguments
printf "Invalid Case 1: " && ./fractol                                 2>/dev/null && echo "NG" || echo "OK"
printf "Invalid Case 2: " && ./fractol hoge                            2>/dev/null && echo "NG" || echo "OK"
printf "Invalid Case 3: " && ./fractol Mandelbrot -c                   2>/dev/null && echo "NG" || echo "OK"
printf "Invalid Case 4: " && ./fractol -z Mandelbrot                   2>/dev/null && echo "NG" || echo "OK"
printf "Invalid Case 5: " && ./fractol -d -1 Julia                     2>/dev/null && echo "NG" || echo "OK"
printf "Invalid Case 6: " && ./fractol -d 360 Julia                    2>/dev/null && echo "NG" || echo "OK"
printf "Invalid Case 7: " && ./fractol -d 99999999999999 Julia         2>/dev/null && echo "NG" || echo "OK"
printf "Invalid Case 8: " && ./fractol -d Julia                        2>/dev/null && echo "NG" || echo "OK"

# Valid Arguments
printf "Valid Case 1: " &&  ./fractol Mandelbrot         && echo "OK" || echo "NG"
printf "Valid Case 2: " &&  ./fractol Julia              && echo "OK" || echo "NG"
printf "Valid Case 3: " &&  ./fractol Barnsley           && echo "OK" || echo "NG"
printf "Valid Case 4: " &&  ./fractol Cyclosorus         && echo "OK" || echo "NG"
printf "Valid Case 5: " &&  ./fractol FractalTree        && echo "OK" || echo "NG"
printf "Valid Case 6: " &&  ./fractol GoldenBee          && echo "OK" || echo "NG"
printf "Valid Case 7: " &&  ./fractol -c Julia           && echo "OK" || echo "NG"
printf "Valid Case 8: " &&  ./fractol -j Julia           && echo "OK" || echo "NG"
printf "Valid Case 9: " &&  ./fractol -d 60 Julia        && echo "OK" || echo "NG"
printf "Valid Case 10: " && ./fractol -c -d 90 Julia     && echo "OK" || echo "NG"
printf "Valid Case 11: " && ./fractol -cjd120 Julia      && echo "OK" || echo "NG"
