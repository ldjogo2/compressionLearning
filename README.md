# compressionTechniques
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


### What I have implemented (And why)
```Note: This will be filled in at the end when I figure out how each method is used and I can comment on each method```
- Huffman compression
- LZW
