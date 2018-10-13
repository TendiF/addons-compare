const addon = require('./build/Release/addon');
function isPalindrome(str) {
    var half = Math.round(str.length / 2);
    var start = 0;
    var end = str.length - 1;
    var palindrome = true;
    var SPACE = 32;
    var COMMA = 44;
    var startSpace, endSpace;
  
    while (half && palindrome) {
      startSpace = str.charCodeAt(start) === SPACE || str.charCodeAt(start) === COMMA;
      endSpace = str.charCodeAt(end) === SPACE ||  str.charCodeAt(end) === COMMA;
  
      if (str[start] == str[end]) {
        start++;
        end--;
      } else if (startSpace || endSpace) {
        startSpace && start++;
        endSpace && end--;
      } else {
        palindrome = false;
      }
  
      half--;
    }
  
    return palindrome;
}
function weirdSum(){
    let i;
    let a = 3.14159265358979323846, b = 5.321123321;
    for(i = 0 ; i < 100000000; i++){
      a += b + i;
    }
    let total = a;
    return total;
  }

let str = 'a man a plan a cat a ham a yak a yam a hat a canal panama';

console.time('C:weirdSum');
console.log(addon.weirdSum());
console.timeEnd('C:weirdSum');

console.time('Javascript:weirdSum');
console.log(weirdSum());
console.timeEnd('Javascript:weirdSum');

console.time('C:isPalindrome');
console.log(addon.isPalindrome(str));
console.timeEnd('C:isPalindrome');

console.time('Javascript:isPalindrome');
console.log(isPalindrome(str));
console.timeEnd('Javascript:isPalindrome');