
function generate(){
    let dictionary = '';
    if (document.getElementById('lowercaseCb').checked) {
        dictionary += 'qwertyuiopasdfghjklzxcvbnm';
    }
    if (document.getElementById('uppercaseCb').checked) {
        dictionary += 'QWERTYUIOPASDFGHJKLZXCVBNM';
    }
    if (document.getElementById('digitsCb').checked) {
        dictionary += '0123456789';
    }
    if (document.getElementById('specialsCb').checked) {
        dictionary += ' !@#$%^&*()_-+={};<>:';
    }


    const length = document.querySelector('input[type="range"]').value;

    if (length < 1 || dictionary.length === 0){
        return;
    }
    let password = '';
    for (let i = 0; i < length; i++){
        const pos = Math.floor(Math.random() * dictionary.length);
        password += dictionary[pos];
    }

    document.querySelector('input[type="text"]').value = password;
}



generate();
