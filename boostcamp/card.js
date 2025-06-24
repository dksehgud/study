function play(){

}

let arr = new Array(100);

for(let i = 0; i < arr.length; i++){
    arr[i] = i + 1;
}

//ÇÇ¼Å ¿¹ÀÌÃ÷ ¼ÅÇÃ
for (let i = arr.length - 1; i > 0; i--) {
    const randomIdx = Math.floor(Math.random() * (i + 1));
    [arr[i], arr[randomIdx]] = [arr[randomIdx], arr[i]];
}

