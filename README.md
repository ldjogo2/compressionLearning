# compressionTechniques
*NOTE: In the middle of creating this repo I discovered a fabulous resource for guiding someone interested in data compresson: https://go-compression.github.io/. Please check this page out as it is great!*

### Generel Info

We need compression to be able to send files over a network in a effecient manner and to be able to save space on our VMs.

The techniques to achieve compression fall under 2 categories: lossy and lossless(def. evident from words).

They can also be known as irreversible compression and reversible compression respectively.

Lossy is used in files where perfect data construction isn't necessary like JPEG, MP3, MPEG. (human senses can't measure data loss)

Lossless is used where confidentiality is needed. Formats like like BMP, GIF, RAW, ONG, etc. use it.
##### Some Lossy Compression Methods
1. Discrete Cosine Transform
2. Vector Quantisation
3. Transform Coding

##### Some Lossless Compression Methods
1. Huffman compression
2. Run Length Encoding
3. string-table compression
4. Lempel Ziff Welch
5. zlib


### What I have implemented
- Huffman compression (Used as core of most industry compression)
- LZW (Used in Unix file compression utility `compress` and in GIF)
- Arithmetic Coding ()


### Random Notes on Methods
```LZW done in a single pass, is more simple and requires no prior info on data stream```

```LZW can cause big problems with certain types of data, being a quite simplistic method for finding patterns.```

```Huffman modified can capture patterns as well as shrink the text size by quite a lot. To me it seems like a far superior basis for an algo.```


### References
1. Geeks for Geeks
