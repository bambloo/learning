const saved_console = window.console
window.console = {
    log: function() {
        
    }
}

const saved_json_parse = JSON.parse
JSON.parse = function(...args) {
    saved_console.log(...args)
    let parsed = saved_json_parse(...args)

    return parsed
}