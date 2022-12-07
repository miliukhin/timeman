var audio = new Audio();
let a=true;
function fn()
{
    if(a==true){
    audio.src = 'uuu.mp3';
    audio.autoplay = true;
    alert("GitHub");
    a=false;
    return 0;
    }
    if(a==false)
    {
        alert("Nie GitHub");
        audio.src = 'uuu.mp3';
        audio.autoplay = false;
        a=true;
        return 0;
    }
}