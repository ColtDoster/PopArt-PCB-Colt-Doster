char pixelMap[54]{
    -1, 0,-1,-1, 1,-1,-1,-1,-1,
     2, 3, 4, 5, 6,-1,-1,-1,-1,
     7, 8, 9,10,11,12,13,-1,-1,
    -1,14,-1,-1,-1,-1,15,16,-1,
    17,-1,18,-1,-1,19,-1,-1,20,
    -1,21,-1,-1, 1,-1,22,23,-1,  
};

char animation [4][24]{
    {                      //2 
      0,      2,
    2,2,2,2,2,
    2,2,2,2,2,2,2,
      1,        0,1,
    0,  1,    0,    1,
      1,        1,1,
  },
    {                     //3    
      1,    2,
    2,2,2,2,2,
    2,2,2,2,2,2,2,
      1,        1,1,
    1,  1,    0,    1,
      0,        0,1,
  },
    {                     //4    
      0,    2,
    2,2,2,2,2,
    2,2,2,2,2,2,2,
      1,        1,1,
    1,  0,    1,    0,
      1,        1,0,
  },
      {                     //5   
      1,    2,
    2,2,2,2,2,
    2,2,2,2,2,2,2,
      0,        1,0,
    1,  1,    1,    0,
      1,        1,1,
  },

};