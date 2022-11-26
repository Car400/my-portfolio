# Program 7
<h2>This directory contains a hash table program from my data structures and algorithms course at Texas State University</h2>
<div>
  <p>When the program starts, it reads the Word.txt file and fills the array by using the length of the words determine where they are placed into the array.
  To deal with any collisions we created a simple rehashing algorithm that takes the current collison index and add one to it so that it can be placed in the next index or any available index.</p>
  <p>Other functions include inserting, searching, hashing, rehahshing, displaying, and deleting elements:</p>
  
  <h3>Insert Function</h3>
  <ul>
    <li>Takes in a string variable and uses hashing functions to sort it into the array. If there is a collison, then call the rehashing function to find the next        available index</li>
  </ul>
  
  <h3>Search Function</h3>
  <ul>
    <li>Takes in a string variable and uses linear probing via the rehashing function to find the desired element in the array</li>
  </ul>
  
  <h3>Hash Function</h3>
  <ul>
    <li>Takes in a string variable and returns the length of the string</li>
  </ul>
  
  <h3>Rehashing Function</h3>
  <ul>
    <li>Takes in an integer and returns the integer plus one</li>
  </ul>
  
  <h3>Delete Function</h3>
  <ul>
    <li>Takes in a string variable and uses the hashing and rehashing function to find the specified element and delete it</li>
  </ul>
  
  <h3>Display Function</h3>
  <ul>
    <li>Displays the hash table</li>
  </ul>
</div>
