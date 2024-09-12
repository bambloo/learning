saved_console.log("injected")

let encrypt_mapping = []
for (const key in window) {
    if (Array.isArray(window[key])) {
        if (window[key].length > 1000 && window[key].length < 2000) {
            encrypt_mapping = window[key]
        }
    }
}

saved_console.log(JSEncrypt)
const saved_decrypt = JSEncrypt.prototype.decrypt
JSEncrypt.prototype.decrypt = function(...args) {
    saved_console.log(...args)
    let decrypted = saved_decrypt.bind(this)(...args)
    saved_console.log(decrypted)
    // if (decrypted.indexOf(',') >= 0) {
    //     return `${decrypted.split(',')[0]},1000`
    // }
    return decrypted
}