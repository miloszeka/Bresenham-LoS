/*                                                                        
 *  _____                     _                __        _____           
 * | __  |___ ___ ___ ___ ___| |_ ___ _____   |  |   ___|   __|          
 * | __ -|  _| -_|_ -| -_|   |   | .'|     |  |  |__| . |__   |          
 * |_____|_| |___|___|___|_|_|_|_|__,|_|_|_|  |_____|___|_____|          
 *                                                                        
 * =======================================================================
 * Copyright (c) <2019> <Milosh Zechevich - zechevichmilosh@gmail.com>

 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * =======================================================================
 * 
 */

/* Returns 1 if there is LoS otherwise 0 */
int checkLoS(x0,y0,x1,y1)
{/*{{{*/
    signed int dX, dY, D, xi, yi;

    dX = x1 - x0;
    dY = y1 - y0;

    if (dX > 0) xi = 1;
    else xi = -1;
    if (dY > 0) yi = 1;
    else yi = -1;

    dX = abs(dX);
    dY = abs(dY);

    if (dY < dX)
    {/*{{{*/
        // x moves in unit intervals
        D  = 2*dY - dX;
        while (x0 != x1)
        {
            if (data[y0][x0] == blockCode)
            {
                return 0;
            }
            if (D > 0)
            {
                y0 += yi;
                D -= 2*dX;
            }
            D += 2*dY;
            x0+=xi;
        }
    }/*}}}*/

    else
    {/*{{{*/
        // y moves in unit intervals
        D = 2*dX - dY;
        while (y0 != y1)
        {
            if (data[y0][x0] == blockCode)
            {
                return 0;
            }
            if (D > 0)
            {
                x0 += xi;
                D -= 2*dY;
            }
            D +=2*dX;
            y0+=yi;
        }
    }/*}}}*/
    return 1;
}/*}}}*/
