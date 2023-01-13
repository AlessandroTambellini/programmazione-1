// See problem on codewars: https://www.codewars.com/kata/55a4f1f67157d8cbe200007b/javascript

/*     
var image = [
      [0,0,0,0],
      [0,1,1,0],
      [0,1,1,0],
      [0,0,0,0],
    ];
 */

function countIslands(image){
    let islands = 0;
    for (let i = 0; i < image.length; i++) {
      for (let j = 0; j < image[0].length; j++) {
        if (image[i][j] === 1) {
          islands++;
          deleteIsland(image, i, j);
        }
      }
    }
    
    return islands;
  }
  
  function deleteIsland(image, row, col) {
    for (let i = row - 1; i <= row + 1; i++) {
      for (let j = col - 1; j <= col + 1; j++) {
        if (i >= 0 && i < image.length && j >= 0 && j < image[0].length && image[i][j] === 1) {
          image[i][j] = 2;
          deleteIsland(image, i, j);
        }
      }
    }
  }