/* XPM */
const char *hydra_xpm[] = {
/* columns rows colors chars-per-pixel */
"32 32 16 1 ",
"  c #290000",
". c #19420F",
"X c #0F7B21",
"o c #7B5220",
"O c #8C2A42",
"+ c #0DA539",
"@ c #5CBD1C",
"# c #22D659",
"$ c #B59D00",
"% c #B6CF00",
"& c #F8E800",
"* c #A57B84",
"= c #EE5B85",
"- c #EFADBE",
"; c white",
": c None",
/* pixels */
"::::::::::::::::::::::::::::::::",
"::::::::::::::::::::::::::::::::",
"::  ::::::::::::::::::::::::::::",
":: # :::::::::::::::::  ::::::::",
":: ## ::::::::::::::: # ::::::::",
":: X## ::::::::::::: +# ::::::::",
"::: X## ::::::::::: X## ::::::::",
"::: X+## :::        +# :::::::::",
":::: X+##   $&+###+..# :::::::::",
":::: XX+##.+$&%++++%&.   :::::::",
":::::  X+##.+$&&&&&&$@.+# ::::::",
"::::::: X++#.+$$....+++.X# :::::",
":::::: X++++#...####.+++.X :::::",
"::::: &X++++++++++###.+++.+ ::::",
"::::: &X++++     .X+##.+++. ::::",
":::: &X++++++       X##.+++. :::",
":::: &X+++++++X  o%o .+#.++. :::",
":::: X+.+++++++X % %   +#.+++ ::",
":::: X.+++++++++.o%o  X++#.+# ::",
":::: X.+++      X.  .XXX++#.## :",
"::::: +++++ ====        XXX++# :",
"::::: ++X ++ =OOOOO = == ..X++ :",
":::: ++X XX++ =O**o  O = ;;.X+ :",
":::: ++X XX+++ =OO*** ; ; ;   ::",
"::: ++X   XX+++ =O**** O : :::::",
"::: XX ::: XX++ ==OO---O :::::::",
":::   ::::: XX++ ==O--O== ::::::",
":::::::::::: XXXX ==OO=== ::::::",
":::::::::::::   XX ====  :::::::",
"::::::::::::::::       :::::::::",
"::::::::::::::::::::::::::::::::",
"::::::::::::::::::::::::::::::::"
};

// Ding!
#define CHORD_LENGTH 8052
const unsigned char chord_ogg[] = { 
79, 103, 103, 83, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 50, 7, 139, 55, 0, 0, 0, 0, 220, 203, 4, 253, 1, 30, 1, 118,
111, 114, 98, 105, 115, 0, 0, 0, 0, 1, 34, 86, 0, 0, 0, 0, 0, 0, 5, 138, 0, 0, 0, 0, 0, 0, 169, 1, 79, 103,
103, 83, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 50, 7, 139, 55, 1, 0, 0, 0, 127, 93, 81, 167, 14, 61, 255, 255, 255,
255, 255, 255, 255, 255, 255, 255, 255, 255, 197, 3, 118, 111, 114, 98, 105, 115, 45, 0, 0, 0, 88,
105, 112, 104, 46, 79, 114, 103, 32, 108, 105, 98, 86, 111, 114, 98, 105, 115, 32, 73, 32, 50, 48, 49,
48, 49, 49, 48, 49, 32, 40, 83, 99, 104, 97, 117, 102, 101, 110, 117, 103, 103, 101, 116, 41, 0, 0, 0,
0, 1, 5, 118, 111, 114, 98, 105, 115, 34, 66, 67, 86, 1, 0, 64, 0, 0, 24, 66, 16, 42, 5, 173, 99, 142, 58,
200, 21, 33, 140, 25, 162, 160, 66, 202, 41, 199, 29, 66, 208, 33, 163, 36, 67, 136, 58, 198, 53, 199,
24, 99, 71, 185, 100, 138, 66, 201, 129, 208, 144, 85, 0, 0, 64, 0, 0, 164, 28, 87, 80, 114, 73, 45,
231, 156, 115, 163, 24, 87, 204, 113, 232, 32, 231, 156, 115, 229, 32, 103, 204, 113, 9, 37, 231,
156, 115, 142, 57, 231, 146, 114, 142, 49, 231, 156, 115, 163, 24, 87, 14, 114, 41, 45, 231, 156,
115, 129, 20, 71, 138, 113, 167, 24, 231, 156, 115, 164, 28, 71, 138, 113, 168, 24, 231, 156, 115,
109, 49, 183, 146, 114, 206, 57, 231, 156, 115, 230, 32, 135, 82, 114, 174, 53, 231, 156, 115, 164,
24, 103, 14, 114, 11, 37, 231, 156, 115, 198, 32, 103, 204, 113, 235, 32, 231, 156, 115, 140, 53,
183, 212, 114, 206, 57, 231, 156, 115, 206, 57, 231, 156, 115, 206, 57, 231, 156, 115, 140, 49, 231,
156, 115, 206, 57, 231, 156, 115, 110, 49, 231, 22, 115, 174, 57, 231, 156, 115, 206, 57, 231, 28,
115, 206, 57, 231, 156, 115, 32, 52, 100, 21, 0, 144, 0, 0, 160, 161, 40, 138, 226, 40, 14, 16, 26,
178, 10, 0, 200, 0, 0, 16, 64, 113, 20, 71, 145, 20, 75, 177, 28, 203, 209, 36, 13, 8, 13, 89, 5, 0, 0, 1,
0, 8, 0, 0, 160, 72, 134, 164, 72, 138, 165, 88, 142, 102, 105, 158, 38, 122, 162, 40, 154, 162, 42,
171, 178, 105, 202, 178, 44, 203, 178, 235, 186, 46, 16, 26, 178, 10, 0, 72, 0, 0, 80, 81, 20, 197,
112, 20, 7, 8, 13, 89, 5, 0, 100, 0, 0, 8, 96, 40, 138, 163, 56, 142, 228, 88, 146, 165, 89, 158, 7, 132,
134, 172, 2, 0, 128, 0, 0, 4, 0, 0, 80, 12, 71, 177, 20, 77, 241, 36, 207, 242, 60, 207, 243, 60, 207,
243, 60, 207, 243, 60, 207, 243, 60, 207, 243, 60, 207, 243, 60, 13, 8, 13, 89, 5, 0, 32, 0, 0, 0, 130,
40, 100, 24, 3, 66, 67, 86, 1, 0, 64, 0, 0, 8, 33, 26, 25, 67, 157, 82, 18, 92, 10, 22, 66, 28, 17, 67, 29,
66, 206, 67, 169, 165, 131, 224, 41, 133, 37, 99, 210, 83, 172, 65, 8, 33, 124, 239, 61, 247, 222,
123, 239, 129, 208, 144, 85, 0, 0, 16, 0, 0, 97, 20, 56, 136, 129, 199, 36, 8, 33, 132, 98, 20, 39, 68,
113, 166, 32, 8, 33, 132, 229, 36, 88, 202, 121, 232, 36, 8, 221, 131, 16, 66, 184, 156, 123, 203,
185, 247, 222, 123, 32, 52, 100, 21, 0, 0, 8, 0, 192, 32, 132, 16, 66, 8, 33, 132, 16, 66, 8, 41, 164,
148, 82, 72, 41, 166, 152, 98, 138, 41, 199, 28, 115, 204, 49, 199, 32, 131, 12, 50, 232, 160, 147,
78, 58, 201, 164, 146, 78, 58, 202, 36, 163, 142, 82, 107, 41, 181, 20, 83, 76, 177, 229, 22, 99, 173,
181, 214, 156, 115, 175, 65, 41, 99, 140, 49, 198, 24, 99, 140, 49, 198, 24, 99, 140, 49, 198, 24, 35,
8, 13, 89, 5, 0, 128, 0, 0, 16, 6, 25, 100, 144, 65, 8, 33, 132, 20, 82, 72, 41, 166, 152, 114, 204, 49,
199, 28, 3, 66, 67, 86, 1, 0, 128, 0, 0, 2, 0, 0, 0, 28, 69, 82, 36, 71, 114, 36, 71, 146, 36, 201, 146,
44, 73, 147, 60, 203, 179, 60, 203, 179, 60, 77, 212, 68, 77, 21, 85, 213, 85, 109, 215, 246, 109, 95,
246, 109, 223, 213, 101, 223, 246, 101, 219, 213, 101, 93, 150, 101, 221, 181, 109, 93, 214, 93, 93,
215, 117, 93, 215, 117, 93, 215, 117, 93, 215, 117, 93, 215, 117, 93, 215, 129, 208, 144, 85, 0, 128,
4, 0, 128, 142, 228, 56, 142, 228, 56, 142, 228, 72, 142, 164, 72, 10, 16, 26, 178, 10, 0, 144, 1, 0,
16, 0, 128, 163, 56, 138, 227, 72, 142, 228, 88, 142, 37, 89, 146, 38, 105, 150, 103, 121, 150, 167,
121, 154, 168, 137, 30, 16, 26, 178, 10, 0, 0, 4, 0, 16, 0, 0, 0, 0, 0, 128, 162, 40, 138, 163, 56, 142,
36, 89, 150, 166, 105, 158, 167, 122, 162, 40, 154, 170, 170, 138, 166, 169, 170, 170, 106, 154,
166, 105, 154, 166, 105, 154, 166, 105, 154, 166, 105, 154, 166, 105, 154, 166, 105, 154, 166, 105,
154, 166, 105, 154, 166, 105, 154, 166, 105, 154, 166, 105, 2, 161, 33, 171, 0, 0, 9, 0, 0, 29, 199,
113, 28, 71, 113, 28, 199, 113, 36, 71, 146, 36, 32, 52, 100, 21, 0, 32, 3, 0, 32, 0, 0, 67, 81, 28, 69,
114, 44, 199, 146, 52, 75, 179, 60, 203, 211, 68, 207, 244, 92, 81, 54, 117, 83, 87, 109, 32, 52, 100,
21, 0, 0, 8, 0, 32, 0, 0, 0, 0, 0, 0, 199, 115, 60, 199, 115, 60, 201, 147, 60, 203, 115, 60, 199, 147,
60, 73, 211, 52, 77, 211, 52, 77, 211, 52, 77, 211, 52, 77, 211, 52, 77, 211, 52, 77, 211, 52, 77, 211,
52, 77, 211, 52, 77, 211, 52, 77, 211, 52, 77, 211, 52, 77, 211, 52, 77, 211, 52, 77, 3, 66, 67, 86, 2,
0, 100, 0, 0, 16, 147, 144, 74, 78, 177, 87, 70, 41, 198, 36, 180, 94, 42, 164, 20, 147, 212, 123, 168,
152, 98, 76, 58, 237, 169, 66, 6, 41, 7, 185, 135, 74, 33, 165, 160, 211, 222, 50, 165, 144, 82, 12,
123, 167, 152, 66, 200, 24, 234, 161, 131, 144, 49, 133, 176, 215, 218, 115, 207, 189, 247, 30, 8,
13, 89, 17, 0, 68, 1, 0, 0, 198, 32, 198, 16, 99, 200, 49, 38, 37, 131, 18, 49, 199, 36, 100, 82, 34,
231, 156, 148, 78, 74, 38, 165, 164, 86, 90, 204, 164, 132, 152, 74, 139, 145, 115, 78, 74, 39, 37,
147, 82, 90, 11, 169, 101, 146, 74, 107, 37, 166, 2, 0, 0, 2, 28, 0, 0, 2, 44, 132, 66, 67, 86, 4, 0, 81,
0, 0, 136, 49, 72, 41, 164, 20, 82, 74, 49, 167, 152, 67, 74, 41, 199, 148, 99, 72, 41, 229, 156, 114,
78, 57, 199, 152, 116, 16, 42, 231, 24, 116, 14, 74, 164, 148, 114, 142, 57, 167, 156, 115, 18, 50, 7,
149, 115, 14, 66, 38, 157, 0, 0, 128, 0, 7, 0, 128, 0, 11, 161, 208, 144, 21, 1, 64, 156, 0, 0, 128, 144,
115, 138, 49, 8, 17, 99, 16, 66, 9, 41, 133, 80, 82, 170, 156, 147, 210, 65, 73, 169, 131, 146, 82, 73,
169, 197, 146, 82, 140, 149, 115, 82, 58, 9, 41, 117, 18, 82, 42, 41, 197, 88, 82, 138, 45, 164, 84,
99, 105, 45, 215, 210, 82, 141, 45, 198, 156, 91, 140, 189, 134, 148, 98, 45, 169, 213, 90, 90, 171,
185, 197, 88, 115, 139, 53, 247, 200, 57, 74, 157, 148, 214, 58, 41, 173, 165, 214, 106, 77, 173,
213, 218, 73, 105, 45, 164, 214, 98, 105, 45, 198, 214, 98, 205, 41, 198, 156, 51, 41, 173, 133, 150,
98, 43, 169, 197, 216, 98, 203, 53, 181, 152, 115, 105, 45, 215, 20, 99, 207, 41, 198, 158, 107, 172,
185, 199, 156, 131, 48, 173, 213, 156, 90, 203, 57, 197, 152, 123, 204, 177, 231, 152, 115, 15, 146,
115, 148, 58, 41, 173, 117, 82, 90, 75, 173, 213, 154, 90, 171, 53, 147, 210, 90, 105, 173, 198, 144,
90, 139, 45, 198, 156, 91, 139, 49, 103, 82, 90, 44, 169, 197, 88, 90, 138, 49, 197, 152, 115, 139,
45, 215, 208, 90, 174, 41, 198, 156, 83, 139, 57, 199, 90, 131, 146, 177, 246, 94, 90, 171, 57, 197,
152, 123, 138, 173, 231, 152, 115, 48, 54, 199, 158, 59, 74, 185, 150, 214, 122, 46, 173, 245, 94,
115, 46, 66, 214, 220, 139, 104, 45, 231, 212, 106, 15, 42, 198, 158, 115, 206, 193, 216, 220, 131,
16, 173, 229, 156, 106, 236, 61, 197, 216, 123, 238, 57, 24, 219, 115, 240, 173, 214, 224, 91, 205,
69, 200, 156, 131, 208, 185, 248, 166, 123, 48, 70, 213, 218, 131, 204, 181, 8, 153, 115, 16, 58,
232, 34, 116, 240, 201, 120, 148, 106, 46, 173, 229, 92, 90, 235, 61, 214, 26, 124, 205, 57, 8, 209,
90, 238, 41, 198, 222, 83, 139, 189, 215, 158, 155, 176, 189, 7, 33, 90, 203, 61, 197, 216, 131, 138,
49, 248, 154, 115, 48, 58, 231, 98, 84, 173, 193, 199, 156, 131, 144, 181, 22, 161, 123, 47, 74, 231,
32, 148, 170, 181, 7, 153, 107, 80, 50, 215, 34, 116, 240, 197, 232, 160, 139, 47, 0, 0, 96, 192, 1, 0,
32, 192, 132, 50, 80, 104, 200, 138, 0, 32, 78, 0, 128, 65, 200, 57, 165, 24, 132, 74, 41, 8, 161, 132,
148, 66, 40, 41, 85, 140, 73, 200, 152, 131, 146, 49, 39, 165, 148, 82, 90, 8, 37, 181, 138, 49, 8,
153, 99, 82, 50, 199, 164, 132, 18, 90, 42, 37, 180, 18, 74, 105, 169, 148, 210, 90, 40, 165, 181,
150, 90, 140, 41, 181, 22, 67, 41, 169, 133, 82, 90, 43, 165, 180, 150, 90, 170, 49, 181, 86, 99, 196,
152, 148, 204, 57, 41, 153, 99, 82, 74, 41, 173, 149, 82, 90, 171, 28, 147, 146, 49, 40, 169, 131,
144, 74, 41, 41, 197, 82, 82, 139, 149, 115, 82, 50, 232, 168, 116, 16, 74, 42, 169, 196, 84, 82, 105,
173, 164, 210, 82, 41, 165, 197, 146, 82, 108, 41, 197, 84, 91, 139, 181, 134, 82, 90, 44, 169, 196,
86, 82, 106, 49, 181, 84, 91, 139, 49, 215, 136, 49, 41, 25, 115, 82, 50, 231, 164, 148, 82, 82, 43,
165, 180, 150, 57, 39, 165, 131, 142, 74, 230, 160, 164, 146, 82, 107, 165, 164, 20, 51, 230, 164,
116, 14, 74, 202, 32, 163, 82, 82, 138, 45, 165, 18, 83, 40, 165, 181, 146, 82, 108, 165, 164, 214,
90, 140, 181, 166, 212, 90, 45, 37, 181, 86, 82, 106, 177, 148, 18, 91, 139, 49, 215, 22, 75, 77, 157,
148, 214, 74, 42, 49, 134, 82, 90, 107, 49, 230, 154, 90, 139, 49, 148, 18, 91, 41, 41, 198, 146, 74,
108, 173, 197, 154, 91, 108, 57, 134, 82, 90, 44, 169, 196, 86, 74, 106, 177, 213, 150, 99, 107, 177,
230, 212, 82, 141, 41, 181, 154, 91, 108, 185, 198, 148, 83, 143, 181, 246, 156, 90, 171, 53, 181,
84, 99, 107, 177, 230, 88, 91, 111, 181, 214, 156, 59, 41, 173, 133, 82, 90, 43, 37, 197, 152, 90,
139, 177, 197, 88, 115, 40, 37, 182, 146, 82, 108, 165, 164, 24, 91, 108, 185, 182, 22, 99, 15, 161,
180, 88, 74, 106, 177, 164, 18, 99, 107, 49, 230, 24, 91, 142, 169, 181, 90, 91, 108, 185, 166, 212,
98, 173, 181, 246, 28, 91, 110, 61, 165, 22, 107, 139, 177, 230, 210, 82, 141, 53, 215, 222, 99, 77,
57, 21, 0, 0, 48, 224, 0, 0, 16, 96, 66, 25, 40, 52, 100, 37, 0, 16, 5, 0, 0, 24, 195, 24, 99, 16, 26, 165,
156, 115, 78, 74, 131, 148, 115, 206, 73, 201, 156, 131, 16, 66, 74, 153, 115, 16, 66, 72, 41, 115,
78, 66, 74, 45, 101, 206, 65, 72, 169, 181, 80, 74, 74, 173, 197, 22, 74, 73, 169, 181, 22, 11, 0, 0,
40, 112, 0, 0, 8, 176, 65, 83, 98, 113, 128, 66, 67, 86, 2, 0, 81, 0, 0, 136, 49, 74, 49, 6, 161, 49, 70,
41, 231, 32, 52, 198, 40, 197, 24, 132, 74, 41, 198, 156, 147, 80, 41, 197, 152, 115, 80, 50, 199,
156, 131, 80, 74, 230, 156, 115, 16, 74, 9, 33, 148, 82, 74, 74, 33, 132, 82, 74, 73, 169, 0, 0, 128, 2,
7, 0, 128, 0, 27, 52, 37, 22, 7, 40, 52, 100, 69, 0, 16, 5, 0, 0, 24, 99, 156, 51, 206, 33, 10, 157, 165,
206, 82, 36, 169, 163, 214, 81, 107, 40, 165, 26, 75, 140, 157, 198, 86, 123, 235, 185, 211, 26, 123,
109, 185, 55, 148, 74, 141, 169, 214, 142, 107, 203, 185, 213, 222, 105, 77, 61, 183, 28, 11, 0, 0,
59, 112, 0, 0, 59, 176, 16, 10, 13, 89, 9, 0, 228, 1, 0, 16, 198, 40, 197, 152, 115, 206, 25, 133, 24,
115, 206, 57, 231, 12, 82, 140, 57, 231, 156, 115, 138, 49, 231, 156, 131, 16, 66, 197, 152, 115,
206, 65, 8, 33, 115, 206, 57, 8, 161, 132, 146, 57, 231, 28, 132, 16, 74, 232, 156, 131, 80, 74, 41,
165, 116, 206, 65, 8, 161, 148, 82, 58, 231, 32, 132, 82, 74, 41, 157, 115, 16, 74, 41, 165, 148, 2, 0,
128, 10, 28, 0, 0, 2, 108, 20, 217, 156, 96, 36, 168, 208, 144, 149, 0, 64, 30, 0, 0, 96, 12, 66, 206,
73, 105, 173, 97, 204, 57, 8, 45, 213, 216, 48, 198, 28, 148, 148, 98, 139, 156, 131, 144, 82, 139,
185, 70, 204, 65, 72, 41, 198, 160, 59, 40, 41, 181, 24, 108, 240, 157, 132, 148, 90, 139, 57, 7, 147,
82, 139, 53, 231, 222, 131, 72, 169, 181, 154, 131, 206, 61, 213, 86, 115, 207, 189, 247, 156, 98,
172, 53, 231, 222, 115, 47, 0, 0, 119, 193, 1, 0, 236, 192, 70, 145, 205, 9, 70, 130, 10, 13, 89, 9, 0,
228, 1, 0, 16, 8, 41, 197, 152, 115, 206, 25, 165, 24, 115, 204, 57, 231, 140, 82, 140, 49, 230, 156,
115, 138, 49, 198, 156, 115, 206, 65, 197, 24, 99, 206, 57, 7, 33, 99, 204, 57, 231, 32, 132, 144, 49,
230, 156, 115, 16, 66, 232, 156, 115, 14, 66, 8, 33, 116, 206, 57, 7, 33, 132, 16, 58, 231, 160, 131,
16, 66, 8, 157, 115, 16, 66, 8, 33, 132, 2, 0, 128, 10, 28, 0, 0, 2, 108, 20, 217, 156, 96, 36, 168, 208,
144, 149, 0, 64, 56, 0, 0, 0, 33, 132, 16, 66, 8, 33, 132, 16, 66, 8, 33, 132, 16, 66, 8, 33, 132, 16, 66,
8, 33, 132, 16, 66, 8, 33, 132, 16, 66, 8, 33, 132, 16, 66, 8, 33, 132, 16, 66, 8, 33, 132, 16, 66, 8, 33,
132, 16, 66, 8, 33, 132, 16, 66, 8, 33, 132, 16, 66, 8, 33, 132, 16, 66, 8, 33, 132, 16, 66, 8, 33, 132,
16, 66, 8, 33, 132, 16, 66, 8, 33, 132, 16, 66, 8, 33, 132, 16, 66, 8, 33, 132, 16, 66, 8, 33, 132, 16,
66, 8, 33, 132, 16, 66, 8, 33, 132, 16, 66, 8, 33, 132, 16, 66, 8, 33, 132, 16, 66, 232, 156, 115, 206,
57, 231, 156, 115, 206, 57, 231, 156, 115, 206, 57, 231, 156, 115, 206, 57, 39, 0, 200, 183, 194, 1,
192, 255, 193, 198, 25, 86, 146, 206, 10, 71, 131, 11, 13, 89, 9, 0, 132, 3, 0, 0, 10, 65, 40, 165, 98,
16, 74, 41, 37, 146, 78, 58, 41, 157, 147, 80, 74, 41, 145, 131, 82, 74, 233, 164, 148, 82, 74, 9, 165,
148, 82, 74, 8, 165, 148, 82, 74, 8, 29, 148, 82, 66, 41, 165, 148, 82, 74, 41, 165, 148, 82, 74, 41,
165, 148, 82, 58, 41, 165, 148, 82, 74, 41, 165, 148, 202, 57, 41, 165, 147, 82, 74, 41, 165, 68, 206,
73, 41, 33, 148, 82, 74, 41, 165, 132, 82, 74, 41, 165, 148, 82, 74, 41, 165, 148, 82, 74, 41, 165,
148, 82, 74, 41, 165, 132, 16, 66, 8, 33, 132, 16, 66, 8, 33, 132, 16, 66, 8, 33, 132, 16, 66, 8, 33,
132, 16, 66, 8, 33, 132, 16, 66, 8, 33, 132, 16, 66, 8, 33, 132, 2, 0, 184, 27, 28, 0, 32, 18, 108, 156,
97, 37, 233, 172, 112, 52, 184, 208, 144, 149, 0, 64, 72, 0, 0, 160, 20, 115, 142, 74, 8, 41, 148, 144,
82, 168, 152, 162, 142, 66, 41, 41, 164, 82, 74, 10, 17, 99, 206, 73, 234, 28, 133, 80, 82, 40, 169,
131, 202, 57, 8, 165, 164, 148, 66, 42, 33, 117, 206, 65, 7, 37, 133, 144, 82, 9, 33, 149, 142, 58,
232, 40, 148, 80, 82, 42, 37, 148, 210, 57, 40, 165, 132, 20, 74, 74, 41, 149, 144, 66, 72, 169, 116,
148, 82, 40, 37, 149, 148, 66, 42, 33, 149, 82, 74, 72, 37, 149, 16, 74, 10, 157, 164, 84, 74, 10, 169,
164, 84, 82, 8, 157, 116, 144, 66, 39, 37, 164, 146, 74, 10, 169, 147, 148, 82, 42, 37, 165, 148, 74,
74, 37, 116, 82, 66, 42, 41, 165, 16, 66, 74, 169, 148, 16, 74, 72, 41, 165, 78, 82, 73, 169, 164, 20,
66, 40, 33, 133, 148, 82, 74, 37, 165, 146, 74, 74, 33, 149, 84, 66, 9, 165, 164, 148, 82, 40, 161,
164, 84, 82, 74, 41, 165, 146, 82, 41, 0, 0, 224, 192, 1, 0, 32, 192, 8, 58, 201, 168, 178, 8, 27, 77,
184, 240, 0, 20, 26, 178, 18, 0, 32, 3, 0, 64, 148, 116, 214, 105, 167, 73, 34, 8, 49, 69, 153, 39, 13,
41, 198, 32, 181, 164, 44, 195, 16, 83, 146, 137, 241, 20, 99, 140, 57, 40, 70, 67, 14, 49, 228, 148,
24, 23, 74, 8, 161, 131, 98, 60, 38, 149, 67, 202, 80, 81, 185, 183, 212, 57, 5, 197, 22, 99, 124, 239,
177, 23, 1, 0, 0, 8, 2, 0, 4, 132, 4, 0, 24, 32, 40, 152, 1, 0, 6, 7, 8, 35, 7, 2, 29, 1, 4, 14, 109, 0, 128,
129, 8, 153, 9, 12, 10, 161, 193, 65, 38, 0, 60, 64, 68, 72, 5, 0, 137, 9, 138, 210, 133, 46, 8, 33, 130,
116, 17, 100, 241, 192, 133, 19, 55, 158, 184, 225, 132, 14, 109, 16, 0, 0, 0, 0, 0, 16, 0, 240, 1, 0,
144, 80, 0, 17, 17, 209, 204, 85, 88, 92, 96, 100, 104, 108, 112, 116, 120, 124, 128, 132, 4, 0, 0, 0,
0, 0, 8, 0, 124, 0, 0, 36, 34, 64, 68, 68, 52, 115, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 1,
0, 0, 0, 0, 0, 0, 0, 0, 64, 64, 64, 0, 0, 0, 0, 0, 32, 0, 0, 0, 64, 64, 79, 103, 103, 83, 0, 0, 128, 84, 0, 0,
0, 0, 0, 0, 50, 7, 139, 55, 2, 0, 0, 0, 91, 189, 93, 148, 46, 1, 1, 1, 11, 79, 89, 85, 83, 87, 122, 103,
114, 107, 112, 114, 100, 106, 99, 102, 97, 103, 97, 106, 99, 101, 101, 106, 96, 96, 96, 93, 96, 94,
102, 88, 96, 91, 91, 87, 87, 85, 96, 97, 89, 96, 109, 0, 10, 14, 86, 216, 249, 165, 254, 0, 58, 15, 0, 0,
0, 28, 51, 86, 31, 188, 0, 213, 217, 226, 223, 181, 190, 103, 207, 72, 8, 22, 231, 206, 181, 60, 200,
115, 204, 128, 26, 49, 242, 35, 190, 150, 77, 127, 24, 205, 214, 177, 144, 176, 140, 167, 171, 245,
30, 206, 75, 254, 119, 28, 175, 184, 29, 135, 224, 86, 197, 119, 94, 242, 63, 243, 138, 187, 181,
111, 110, 231, 127, 66, 102, 97, 23, 135, 166, 199, 66, 27, 12, 0, 68, 55, 209, 192, 67, 171, 206, 2,
52, 53, 62, 46, 239, 127, 56, 238, 127, 219, 163, 149, 106, 29, 15, 175, 109, 140, 118, 81, 87, 85,
159, 253, 246, 113, 14, 71, 233, 189, 154, 222, 207, 165, 169, 219, 55, 177, 5, 210, 165, 3, 243,
219, 181, 24, 36, 246, 78, 76, 98, 212, 175, 55, 108, 0, 15, 49, 127, 97, 92, 239, 164, 151, 71, 105,
79, 113, 142, 71, 23, 242, 94, 59, 109, 45, 19, 63, 100, 102, 1, 108, 61, 62, 27, 120, 0, 0, 77, 101, 3,
99, 108, 207, 157, 99, 35, 41, 180, 60, 60, 80, 226, 60, 255, 127, 169, 213, 32, 62, 16, 9, 159, 180,
218, 179, 227, 243, 84, 231, 229, 106, 48, 7, 199, 231, 255, 134, 74, 56, 62, 196, 177, 128, 108,
205, 78, 134, 218, 120, 148, 232, 136, 123, 122, 170, 90, 233, 8, 231, 153, 171, 181, 63, 215, 49,
74, 224, 56, 236, 74, 185, 93, 191, 87, 6, 148, 193, 21, 156, 103, 1, 106, 181, 62, 233, 192, 185, 3,
9, 231, 204, 233, 198, 253, 114, 160, 33, 26, 33, 136, 19, 217, 96, 162, 188, 174, 49, 38, 32, 58,
203, 185, 56, 197, 62, 9, 248, 88, 208, 121, 81, 40, 191, 159, 80, 250, 154, 123, 25, 111, 232, 93,
161, 158, 6, 201, 24, 217, 38, 187, 90, 187, 204, 236, 246, 63, 68, 91, 126, 194, 30, 209, 238, 9, 89,
22, 2, 0, 140, 195, 94, 10, 179, 246, 129, 70, 185, 5, 24, 46, 204, 59, 237, 119, 58, 78, 142, 49, 237,
111, 134, 90, 183, 197, 135, 91, 127, 68, 67, 33, 29, 84, 229, 170, 120, 124, 153, 241, 226, 136,
113, 22, 162, 251, 17, 151, 44, 136, 251, 168, 156, 86, 226, 235, 77, 17, 110, 30, 152, 116, 185, 76,
108, 157, 61, 227, 139, 217, 142, 65, 150, 189, 140, 137, 83, 204, 186, 165, 107, 126, 110, 179,
210, 76, 4, 154, 235, 99, 19, 224, 32, 130, 14, 251, 170, 247, 3, 192, 1, 72, 88, 19, 170, 82, 210,
162, 182, 246, 119, 116, 235, 191, 135, 219, 195, 79, 205, 109, 172, 142, 137, 5, 194, 45, 107, 23,
228, 182, 253, 138, 171, 161, 202, 39, 243, 219, 190, 122, 134, 109, 26, 226, 36, 215, 173, 60, 247,
81, 97, 214, 214, 172, 126, 188, 187, 83, 66, 170, 161, 226, 21, 104, 2, 82, 244, 64, 120, 78, 49,
157, 174, 210, 77, 162, 52, 112, 110, 195, 140, 25, 41, 101, 46, 247, 235, 128, 135, 183, 198, 209,
44, 54, 238, 122, 43, 143, 170, 193, 9, 158, 99, 35, 21, 235, 69, 8, 0, 222, 251, 83, 53, 0, 84, 208,
240, 204, 73, 29, 30, 77, 110, 13, 13, 160, 255, 230, 183, 142, 197, 57, 179, 95, 137, 251, 55, 70,
247, 84, 167, 166, 21, 49, 233, 51, 48, 28, 202, 187, 53, 184, 29, 85, 24, 58, 97, 210, 173, 13, 68,
231, 126, 212, 126, 173, 76, 237, 243, 204, 68, 221, 158, 59, 55, 57, 139, 20, 154, 77, 223, 94, 211,
222, 38, 171, 81, 213, 164, 103, 82, 83, 118, 63, 233, 52, 80, 204, 106, 93, 71, 216, 141, 183, 177,
88, 65, 110, 44, 83, 55, 40, 254, 43, 100, 30, 56, 232, 128, 131, 135, 3, 144, 83, 211, 48, 40, 114,
49, 151, 87, 118, 95, 126, 118, 56, 94, 225, 211, 184, 42, 50, 196, 217, 72, 208, 77, 163, 199, 232,
59, 139, 117, 37, 185, 165, 34, 62, 85, 161, 199, 152, 5, 238, 251, 175, 123, 203, 84, 7, 42, 111, 19,
178, 237, 177, 23, 54, 110, 223, 144, 52, 245, 111, 3, 125, 104, 75, 111, 241, 107, 54, 98, 38, 64,
164, 178, 136, 203, 38, 236, 58, 48, 144, 214, 93, 155, 171, 173, 146, 116, 95, 197, 91, 127, 143,
27, 162, 215, 116, 51, 210, 147, 25, 44, 0, 190, 27, 100, 30, 0, 38, 192, 131, 0, 14, 35, 231, 96, 67,
232, 122, 89, 61, 237, 88, 115, 107, 101, 98, 150, 139, 155, 141, 47, 69, 86, 129, 248, 141, 66, 40,
28, 57, 165, 35, 158, 71, 149, 57, 123, 61, 141, 240, 203, 29, 247, 241, 57, 58, 3, 87, 227, 99, 14,
102, 117, 172, 237, 60, 131, 104, 23, 162, 77, 57, 102, 240, 72, 236, 72, 119, 7, 31, 57, 168, 247,
217, 211, 177, 17, 207, 76, 195, 116, 168, 50, 108, 51, 158, 191, 44, 91, 21, 26, 212, 90, 210, 195,
195, 226, 5, 0, 94, 251, 67, 30, 36, 8, 32, 247, 162, 78, 0, 168, 135, 2, 192, 224, 82, 23, 193, 250,
230, 159, 229, 209, 185, 149, 176, 42, 105, 13, 117, 248, 66, 116, 135, 82, 105, 25, 14, 143, 189,
228, 72, 174, 105, 112, 104, 5, 9, 92, 132, 161, 85, 193, 128, 222, 135, 221, 13, 193, 230, 204, 79,
54, 200, 63, 198, 245, 130, 57, 22, 206, 150, 103, 231, 185, 161, 238, 2, 27, 190, 213, 42, 107, 167,
198, 203, 159, 198, 233, 20, 24, 25, 25, 84, 175, 92, 131, 101, 175, 230, 117, 216, 151, 25, 59, 69,
131, 236, 189, 145, 0, 254, 218, 195, 18, 36, 168, 160, 225, 146, 34, 146, 135, 2, 192, 224, 86, 30,
162, 190, 8, 236, 151, 83, 255, 221, 255, 230, 34, 238, 191, 170, 189, 64, 137, 30, 245, 169, 171,
200, 85, 137, 83, 237, 74, 159, 166, 154, 32, 248, 132, 1, 177, 237, 47, 72, 228, 29, 4, 156, 131,
101, 187, 143, 87, 221, 18, 118, 24, 81, 246, 143, 247, 208, 133, 62, 169, 52, 173, 206, 219, 59,
239, 142, 59, 20, 49, 48, 158, 208, 57, 157, 244, 246, 75, 244, 13, 105, 112, 161, 197, 123, 182, 35,
142, 255, 150, 49, 214, 219, 207, 128, 132, 4, 0, 222, 186, 227, 18, 36, 208, 160, 233, 49, 94, 146,
131, 100, 230, 156, 162, 183, 179, 206, 126, 249, 139, 201, 230, 129, 120, 118, 213, 12, 118, 168,
218, 118, 46, 246, 197, 128, 231, 122, 47, 121, 250, 26, 234, 48, 184, 135, 190, 174, 253, 21, 48,
119, 1, 92, 154, 47, 157, 23, 193, 124, 11, 15, 26, 118, 17, 68, 107, 135, 239, 84, 155, 9, 69, 25,
217, 86, 68, 251, 101, 103, 139, 21, 26, 180, 132, 212, 231, 143, 35, 170, 215, 84, 57, 117, 114,
143, 26, 116, 26, 126, 10, 228, 20, 184, 70, 7, 28, 229, 96, 148, 92, 137, 132, 72, 183, 98, 106, 120,
82, 122, 186, 62, 84, 166, 189, 177, 178, 49, 228, 208, 231, 204, 33, 146, 211, 154, 195, 236, 206,
187, 238, 253, 116, 235, 52, 174, 47, 42, 247, 145, 247, 116, 116, 12, 76, 44, 212, 220, 77, 38, 3,
151, 106, 199, 124, 166, 53, 229, 110, 78, 136, 166, 54, 225, 93, 228, 208, 119, 68, 178, 117, 183,
1, 106, 225, 127, 168, 210, 37, 206, 16, 174, 174, 50, 241, 61, 15, 65, 100, 43, 240, 74, 71, 147, 0,
62, 26, 196, 20, 8, 163, 2, 118, 76, 211, 226, 85, 148, 35, 209, 69, 107, 116, 58, 57, 120, 106, 55,
146, 184, 84, 253, 171, 154, 162, 155, 234, 223, 122, 13, 96, 74, 199, 45, 162, 34, 150, 228, 147,
72, 181, 172, 87, 134, 239, 154, 239, 137, 124, 109, 207, 139, 119, 169, 135, 114, 12, 191, 23, 171,
98, 87, 103, 33, 206, 42, 98, 14, 101, 27, 188, 222, 46, 100, 13, 38, 76, 56, 215, 26, 190, 83, 177,
172, 73, 129, 118, 237, 232, 120, 10, 88, 241, 0, 62, 10, 68, 18, 0, 2, 224, 149, 31, 7, 160, 116, 17,
245, 33, 66, 235, 194, 225, 148, 132, 61, 253, 32, 30, 223, 158, 152, 27, 2, 80, 175, 118, 163, 16,
213, 247, 80, 246, 24, 97, 165, 142, 7, 174, 197, 214, 179, 248, 55, 192, 218, 53, 236, 217, 190, 34,
216, 94, 253, 238, 157, 58, 164, 21, 194, 159, 181, 143, 60, 81, 155, 17, 3, 191, 36, 222, 236, 1, 39,
67, 64, 34, 140, 186, 87, 99, 88, 149, 202, 244, 212, 77, 198, 70, 253, 14, 144, 192, 27, 4, 0, 62, 42,
68, 28, 0, 0, 28, 217, 65, 4, 31, 89, 210, 166, 171, 109, 78, 61, 188, 234, 67, 35, 186, 99, 77, 176,
169, 21, 135, 218, 142, 122, 108, 226, 127, 177, 87, 49, 245, 72, 239, 75, 154, 155, 47, 55, 116,
234, 58, 17, 47, 238, 94, 188, 91, 157, 84, 196, 160, 172, 93, 74, 68, 196, 202, 3, 50, 31, 190, 218,
18, 136, 214, 34, 55, 112, 114, 243, 12, 161, 219, 95, 182, 212, 54, 149, 157, 64, 105, 220, 54, 221,
90, 64, 62, 135, 7, 30, 42, 68, 20, 0, 0, 28, 81, 186, 55, 164, 224, 33, 250, 151, 234, 47, 203, 213,
248, 89, 247, 146, 209, 118, 177, 158, 245, 161, 83, 93, 241, 242, 60, 88, 39, 67, 92, 252, 219, 58,
191, 117, 10, 105, 181, 156, 92, 93, 238, 13, 165, 156, 25, 229, 163, 5, 171, 178, 214, 123, 139,
210, 7, 229, 181, 106, 172, 180, 161, 242, 201, 81, 182, 189, 62, 51, 53, 246, 238, 244, 223, 133,
155, 189, 177, 151, 206, 38, 132, 250, 12, 127, 50, 113, 251, 63, 4, 242, 72, 234, 133, 3, 254, 73, 4,
0, 0, 0, 59, 10, 152, 9, 30, 10, 233, 252, 255, 32, 204, 156, 19, 218, 204, 109, 62, 153, 81, 59, 13,
114, 244, 249, 218, 213, 70, 106, 236, 239, 142, 89, 231, 128, 88, 16, 204, 70, 42, 119, 152, 3, 63,
57, 37, 245, 116, 174, 80, 172, 208, 205, 217, 63, 47, 233, 217, 181, 182, 26, 36, 184, 183, 199,
227, 241, 139, 116, 178, 246, 90, 27, 149, 101, 106, 61, 37, 110, 220, 105, 9, 57, 59, 17, 41, 120,
225, 224, 65, 215, 1, 254, 41, 4, 0, 0, 0, 111, 0, 128, 60, 172, 57, 66, 170, 215, 53, 176, 221, 159,
209, 105, 130, 155, 214, 144, 209, 68, 209, 118, 223, 168, 86, 57, 124, 213, 213, 42, 249, 254, 169,
159, 38, 171, 123, 183, 146, 174, 229, 85, 116, 242, 156, 116, 116, 90, 173, 199, 180, 16, 103, 106,
213, 195, 66, 25, 58, 6, 15, 133, 173, 237, 179, 24, 186, 159, 78, 171, 99, 103, 210, 116, 175, 140,
209, 9, 245, 187, 89, 23, 218, 27, 100, 115, 41, 110, 180, 62, 77, 107, 205, 162, 3, 173, 180, 166, 3,
158, 249, 195, 20, 24, 0, 112, 20, 48, 50, 87, 72, 44, 125, 213, 225, 222, 135, 244, 82, 226, 154,
178, 253, 33, 188, 49, 235, 106, 191, 143, 33, 54, 136, 114, 239, 59, 157, 245, 46, 34, 232, 59, 97,
214, 149, 255, 209, 225, 85, 234, 77, 93, 47, 196, 196, 110, 107, 158, 30, 5, 21, 184, 225, 12, 189,
103, 108, 98, 167, 239, 248, 145, 39, 227, 103, 117, 87, 185, 11, 111, 101, 49, 25, 79, 222, 95, 151,
89, 70, 28, 3, 146, 114, 207, 176, 197, 16, 0, 94, 249, 195, 20, 56, 0, 240, 102, 18, 72, 48, 130, 203,
73, 102, 226, 29, 50, 8, 119, 52, 175, 201, 235, 139, 207, 76, 107, 229, 160, 186, 228, 93, 171, 1,
101, 72, 212, 183, 113, 206, 221, 79, 6, 145, 131, 77, 25, 114, 237, 107, 184, 189, 160, 26, 110,
202, 211, 122, 100, 25, 122, 219, 89, 73, 215, 71, 185, 119, 107, 250, 166, 92, 239, 136, 213, 47,
202, 87, 192, 122, 131, 115, 196, 95, 171, 137, 57, 190, 247, 150, 115, 124, 183, 125, 197, 237,
142, 71, 218, 3, 126, 25, 4, 0, 0, 0, 23, 2, 210, 156, 72, 72, 194, 50, 169, 21, 150, 245, 117, 98, 238,
63, 47, 89, 45, 33, 108, 20, 203, 243, 175, 137, 77, 193, 249, 134, 206, 218, 207, 56, 38, 144, 51,
53, 169, 149, 68, 60, 187, 184, 161, 139, 51, 93, 205, 230, 211, 234, 92, 167, 235, 103, 209, 248,
230, 14, 164, 0, 190, 76, 168, 55, 251, 233, 180, 250, 149, 80, 131, 166, 178, 17, 187, 176, 157,
138, 149, 171, 253, 157, 34, 83, 213, 66, 183, 217, 16, 97, 242, 170, 0, 190, 248, 227, 0, 0, 0, 142,
108, 75, 241, 42, 6, 102, 51, 41, 49, 209, 18, 156, 218, 119, 164, 26, 53, 170, 211, 87, 238, 221,
183, 62, 141, 33, 99, 143, 98, 184, 24, 4, 226, 207, 6, 7, 201, 6, 238, 208, 180, 218, 55, 106, 29,
239, 124, 169, 55, 79, 93, 197, 117, 191, 8, 82, 218, 239, 138, 252, 160, 104, 201, 64, 148, 209,
154, 174, 151, 80, 185, 128, 151, 128, 158, 36, 232, 111, 75, 40, 14, 122, 61, 222, 119, 209, 180,
102, 217, 118, 23, 253, 188, 235, 248, 49, 164, 120, 0, 30, 249, 163, 0, 28, 0, 56, 8, 176, 19, 33, 73,
26, 74, 210, 203, 73, 251, 235, 114, 176, 102, 201, 111, 153, 19, 143, 53, 11, 244, 188, 31, 45, 191,
141, 170, 245, 239, 197, 6, 244, 243, 176, 204, 151, 82, 63, 197, 170, 180, 62, 31, 56, 166, 117,
122, 72, 111, 9, 185, 171, 163, 254, 84, 226, 217, 236, 225, 61, 190, 184, 117, 172, 79, 252, 53, 33,
60, 209, 255, 43, 242, 216, 121, 45, 10, 92, 31, 171, 110, 246, 86, 201, 103, 0, 0, 254, 232, 163, 0,
28, 0, 216, 1, 201, 80, 72, 82, 92, 236, 13, 86, 141, 241, 15, 150, 237, 174, 184, 189, 94, 198, 90,
13, 154, 17, 37, 68, 170, 51, 182, 168, 251, 101, 119, 55, 72, 215, 42, 183, 141, 153, 171, 94, 253,
46, 159, 254, 67, 224, 126, 242, 34, 173, 19, 74, 58, 112, 34, 74, 17, 206, 134, 198, 79, 147, 83,
182, 220, 135, 213, 222, 39, 132, 26, 43, 146, 22, 86, 231, 40, 114, 243, 181, 214, 58, 155, 205, 32,
139, 47, 0, 254, 24, 4, 0, 0, 0, 79, 1, 56, 228, 236, 36, 73, 251, 123, 227, 217, 116, 107, 53, 144,
113, 182, 87, 170, 201, 78, 32, 126, 149, 246, 199, 4, 23, 32, 132, 189, 253, 193, 213, 171, 115,
209, 128, 242, 10, 138, 208, 248, 39, 173, 187, 199, 126, 50, 44, 153, 168, 189, 43, 165, 40, 249,
16, 107, 80, 70, 98, 189, 212, 163, 137, 85, 97, 133, 174, 55, 179, 170, 229, 235, 20, 210, 246, 17,
225, 161, 223, 89, 176, 68, 172, 73, 83, 7, 0, 126, 248, 211, 0, 0, 0, 46, 154, 119, 91, 48, 37, 73, 50,
231, 213, 126, 146, 113, 199, 93, 204, 227, 186, 185, 108, 42, 2, 178, 196, 247, 136, 254, 27, 145,
69, 7, 29, 142, 156, 106, 99, 101, 109, 181, 168, 15, 68, 236, 164, 188, 56, 231, 224, 91, 133, 213,
216, 79, 110, 242, 154, 11, 246, 120, 6, 186, 160, 28, 102, 186, 12, 205, 233, 29, 222, 192, 161,
220, 217, 234, 141, 143, 36, 86, 120, 223, 229, 223, 212, 245, 236, 0, 190, 248, 3, 0, 0, 0, 15, 0,
143, 193, 37, 73, 106, 54, 26, 228, 225, 219, 203, 253, 82, 142, 139, 180, 5, 8, 247, 126, 197, 209,
210, 180, 74, 178, 14, 94, 77, 177, 127, 87, 57, 152, 140, 234, 233, 179, 184, 41, 38, 115, 149, 229,
166, 174, 39, 173, 160, 83, 47, 189, 94, 207, 34, 124, 179, 192, 121, 171, 60, 255, 49, 143, 70, 176,
188, 96, 182, 24, 40, 122, 59, 253, 239, 132, 102, 240, 253, 121, 87, 147, 118, 214, 89, 57, 105, 4,
30, 232, 179, 0, 0, 0, 46, 44, 24, 146, 36, 153, 109, 161, 197, 223, 198, 87, 75, 13, 108, 173, 243,
65, 2, 117, 210, 72, 111, 20, 62, 21, 50, 210, 97, 239, 122, 183, 127, 175, 104, 232, 173, 86, 255,
185, 250, 197, 143, 59, 107, 118, 74, 123, 49, 203, 30, 94, 125, 99, 53, 178, 247, 158, 175, 103,
150, 44, 202, 235, 142, 80, 60, 31, 94, 52, 242, 214, 135, 118, 42, 43, 139, 165, 218, 172, 2, 163,
86, 74, 171, 192, 12, 0, 30, 232, 211, 0, 0, 0, 158, 120, 6, 28, 138, 9, 39, 201, 153, 102, 87, 77, 76,
143, 5, 233, 96, 82, 250, 117, 196, 132, 161, 33, 137, 12, 13, 249, 35, 25, 21, 144, 18, 128, 84, 102,
72, 109, 11, 1, 193, 232, 99, 52, 53, 126, 99, 43, 60, 153, 47, 62, 155, 101, 17, 241, 110, 36, 208,
94, 3, 195, 182, 177, 67, 174, 83, 122, 52, 94, 104, 207, 83, 229, 166, 87, 142, 222, 245, 188, 250,
152, 186, 154, 76, 157, 252, 108, 16, 199, 51, 156, 251, 107, 79, 0, 62, 232, 227, 0, 0, 0, 46, 18,
228, 132, 36, 169, 213, 111, 194, 41, 233, 164, 45, 219, 145, 165, 230, 48, 236, 77, 170, 122, 196,
46, 161, 191, 17, 129, 67, 58, 85, 115, 53, 84, 19, 125, 105, 9, 3, 255, 126, 86, 140, 63, 214, 102,
141, 26, 96, 89, 82, 33, 82, 215, 88, 31, 26, 207, 157, 240, 106, 30, 38, 101, 180, 2, 141, 113, 43,
116, 114, 251, 139, 192, 123, 126, 93, 105, 155, 98, 181, 5, 254, 199, 147, 0, 0, 0, 118, 8, 146, 138,
36, 73, 102, 216, 148, 187, 108, 175, 246, 158, 74, 155, 180, 173, 138, 83, 81, 46, 183, 170, 19,
120, 3, 65, 87, 103, 240, 89, 244, 104, 241, 61, 145, 41, 182, 190, 182, 59, 223, 19, 57, 108, 186,
195, 185, 157, 60, 95, 103, 185, 255, 232, 148, 247, 110, 175, 237, 89, 31, 250, 78, 86, 10, 174, 87,
141, 239, 89, 60, 79, 122, 167, 235, 214, 120, 237, 227, 142, 22, 183, 168, 222, 250, 195, 134, 1,
94, 216, 3, 0, 0, 0, 237, 1, 146, 146, 36, 65, 218, 13, 22, 70, 124, 211, 170, 138, 226, 203, 154, 74,
195, 250, 213, 78, 119, 204, 34, 31, 203, 217, 84, 213, 111, 221, 16, 39, 118, 75, 67, 224, 204, 66,
112, 6, 214, 42, 37, 203, 155, 223, 124, 192, 142, 155, 238, 199, 138, 14, 28, 83, 249, 166, 56, 161,
165, 154, 114, 159, 113, 107, 177, 30, 147, 249, 200, 234, 86, 7, 99, 47, 21, 147, 177, 125, 87, 139,
5, 254, 167, 3, 0, 0, 0, 109, 61, 78, 78, 82, 88, 5, 97, 45, 14, 214, 242, 138, 174, 218, 23, 76, 144,
110, 205, 185, 89, 203, 100, 251, 207, 220, 151, 120, 93, 216, 231, 2, 179, 179, 197, 93, 206, 190,
37, 20, 60, 235, 154, 42, 38, 211, 150, 152, 60, 189, 8, 250, 226, 162, 37, 184, 41, 65, 187, 138,
233, 71, 174, 72, 28, 112, 222, 103, 155, 150, 43, 78, 246, 153, 213, 171, 66, 243, 93, 31, 225, 174,
113, 0, 62, 184, 35, 160, 1, 128, 14, 59, 64, 231, 152, 36, 57, 6, 228, 246, 75, 53, 241, 201, 222,
179, 157, 241, 212, 237, 54, 69, 168, 97, 239, 71, 163, 108, 21, 252, 162, 194, 205, 29, 157, 129,
97, 127, 220, 85, 183, 173, 5, 198, 70, 185, 210, 185, 207, 86, 90, 52, 189, 251, 139, 117, 122, 190,
251, 136, 118, 14, 119, 73, 161, 0, 1, 188, 233, 230, 153, 43, 20, 169, 172, 15, 52, 215, 130, 29, 0,
254, 151, 3, 224, 0, 0, 236, 128, 196, 150, 36, 41, 202, 193, 244, 33, 186, 26, 158, 108, 99, 118,
210, 152, 39, 63, 118, 122, 85, 173, 33, 122, 104, 88, 126, 162, 140, 19, 172, 226, 235, 89, 133,
147, 167, 89, 177, 109, 51, 142, 16, 173, 7, 107, 139, 163, 89, 217, 91, 123, 78, 162, 68, 88, 91,
105, 220, 141, 229, 184, 202, 231, 158, 137, 153, 148, 214, 216, 238, 158, 106, 127, 220, 85, 249,
21, 0, 62, 152, 67, 160, 1, 128, 14, 23, 9, 66, 146, 164, 102, 116, 26, 78, 55, 87, 250, 124, 185, 55,
14, 103, 111, 19, 94, 130, 13, 50, 39, 33, 16, 211, 140, 107, 252, 94, 133, 39, 186, 241, 82, 176,
191, 47, 101, 118, 104, 164, 23, 194, 54, 54, 29, 41, 165, 255, 113, 210, 99, 229, 106, 173, 73, 80,
86, 47, 156, 167, 83, 48, 240, 78, 24, 220, 41, 255, 254, 172, 35, 59, 220, 169, 1, 62, 136, 99, 96, 1,
128, 5, 59, 116, 80, 97, 78, 98, 210, 192, 151, 109, 186, 67, 215, 54, 213, 113, 122, 24, 78, 207, 21,
175, 108, 129, 19, 61, 96, 167, 158, 46, 198, 1, 17, 138, 118, 229, 154, 226, 55, 186, 52, 173, 23,
241, 169, 97, 185, 121, 71, 150, 128, 192, 220, 203, 38, 22, 36, 103, 126, 118, 72, 35, 154, 136, 90,
132, 214, 35, 150, 136, 199, 121, 161, 220, 46, 253, 164, 76, 238, 32, 160, 68, 213, 182, 235, 50,
95, 38, 0, 254, 87, 67, 196, 2, 0, 19, 218, 21, 153, 115, 146, 32, 126, 255, 126, 139, 197, 63, 231,
117, 46, 108, 143, 85, 250, 186, 24, 28, 187, 117, 144, 153, 103, 34, 203, 160, 171, 186, 2, 174,
116, 9, 239, 189, 205, 97, 172, 32, 207, 245, 87, 55, 181, 85, 99, 53, 0, 0, 253, 236, 213, 97, 39,
240, 188, 246, 85, 48, 24, 206, 42, 195, 22, 146, 85, 206, 178, 101, 109, 21, 42, 101, 107, 139, 85,
49, 185, 181, 110, 57, 172, 82, 112, 155, 10, 0, 62, 72, 83, 224, 6, 128, 8, 109, 139, 182, 147, 36,
14, 158, 253, 135, 225, 92, 111, 79, 229, 240, 219, 214, 65, 100, 103, 140, 154, 249, 93, 15, 66,
171, 37, 67, 168, 39, 14, 173, 29, 148, 229, 204, 17, 163, 93, 28, 202, 165, 8, 134, 79, 10, 132, 212,
225, 64, 225, 163, 197, 153, 223, 227, 254, 232, 142, 34, 20, 60, 237, 105, 237, 217, 121, 142, 87,
142, 94, 142, 2, 115, 249, 176, 168, 40, 42, 7, 0, 62, 248, 106, 58, 1, 64, 14, 237, 108, 39, 199, 100,
65, 170, 88, 119, 30, 127, 13, 190, 177, 236, 99, 162, 188, 195, 131, 226, 118, 70, 71, 173, 208,
222, 90, 153, 50, 78, 67, 110, 246, 47, 211, 89, 52, 228, 6, 33, 83, 187, 205, 129, 254, 86, 107, 233,
156, 94, 150, 188, 91, 71, 47, 161, 206, 59, 52, 99, 68, 200, 187, 117, 78, 41, 155, 242, 191, 90, 55,
68, 214, 189, 130, 74, 229, 168, 174, 149, 89, 117, 160, 212, 121, 93, 144, 33, 94, 152, 74, 169, 63,
0, 87, 50, 122, 59, 0, 182, 109, 219, 178, 29, 50, 123, 215, 211, 145, 149, 213, 157, 57, 113, 100,
121, 52, 184, 214, 179, 167, 139, 152, 181, 216, 21, 126, 184, 53, 207, 63, 95, 111, 251, 42, 170,
112, 98, 212, 252, 39, 189, 83, 34, 42, 181, 25, 21, 137, 106, 10, 128, 182, 153, 18, 68, 133, 117,
123, 26, 48, 54, 14, 220, 158, 70, 168, 130, 96, 181, 221, 70, 41, 91, 75, 111, 183, 172, 34, 45, 163,
72, 84, 225, 48, 106, 219, 108, 21, 137, 42, 108, 70, 69, 224, 5, 0, 79, 103, 103, 83, 0, 4, 192, 105,
0, 0, 0, 0, 0, 0, 50, 7, 139, 55, 3, 0, 0, 0, 187, 239, 240, 30, 11, 118, 105, 30, 33, 29, 35, 31, 29, 1, 1,
1, 62, 40, 219, 65, 21, 0, 28, 180, 181, 109, 219, 182, 109, 7, 32, 149, 182, 112, 92, 235, 206, 193,
153, 199, 59, 69, 202, 118, 18, 235, 216, 248, 208, 188, 245, 126, 78, 54, 95, 245, 218, 251, 119,
154, 79, 122, 95, 187, 76, 106, 222, 122, 63, 71, 63, 169, 94, 187, 204, 213, 124, 210, 251, 57, 153,
212, 188, 245, 102, 142, 126, 82, 189, 118, 153, 211, 188, 245, 126, 78, 38, 85, 91, 151, 57, 250,
73, 245, 106, 50, 209, 188, 245, 6, 163, 75, 213, 102, 50, 71, 223, 202, 50, 153, 224, 173, 11, 142,
146, 170, 101, 50, 1, 234, 254, 90, 37, 1, 94, 88, 250, 65, 4, 128, 8, 172, 104, 219, 182, 237, 132,
167, 235, 167, 163, 215, 201, 51, 105, 58, 178, 39, 122, 165, 3, 193, 31, 103, 123, 169, 161, 251,
232, 117, 226, 201, 77, 251, 232, 51, 241, 228, 166, 61, 120, 66, 219, 243, 59, 241, 228, 252, 122,
212, 75, 180, 211, 209, 235, 196, 147, 155, 246, 81, 147, 40, 57, 191, 158, 188, 68, 219, 243, 59,
120, 114, 190, 143, 154, 68, 201, 249, 13, 79, 104, 123, 126, 195, 7, 172, 213, 213, 170, 167, 175,
174, 246, 80, 171, 198, 187, 38, 0, 94, 248, 249, 57, 127, 0, 240, 32, 73, 0, 0, 52, 152, 63, 18, 154,
91, 172, 190, 244, 32, 20, 137, 197, 174, 30, 96, 121, 14, 0, 94, 248, 249, 57, 127, 0, 240, 32, 137,
160, 0, 128, 135, 214, 118, 31, 10, 86, 227, 101, 208, 79, 115, 104, 148, 172, 65, 119, 156, 133, 14,
20, 0, 94, 248, 249, 57, 127, 0, 240, 192, 37, 10, 0, 120, 64, 240, 57, 128, 70, 0, 31, 11, 231, 248, 3,
101, 93, 77, 210, 29, 0, 94, 8, 250, 37, 254, 0, 16, 129, 112, 18, 5, 64, 173, 253, 35, 19, 36, 15, 25,
1, 134, 231, 225, 240, 143, 22, 61, 9, 135, 228, 199, 5, 160, 0, 2, 94, 8, 250, 5, 127, 0, 136, 96, 74,
148, 2, 0, 30, 96, 249, 58, 48, 73, 141, 230, 121, 0, 231, 208, 41, 112, 98, 179, 29, 160, 1, 94, 24,
250, 75, 252, 1, 32, 2, 33, 81, 0, 128, 190, 165, 172, 123, 111, 12, 44, 229, 10, 94, 28, 52, 249, 162,
191, 56, 18, 14, 14, 14};
