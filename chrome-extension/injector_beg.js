function injectScript (src) {
    const s = document.createElement('script');
    s.src = chrome.runtime.getURL(src);
    // s.onload = () => s.remove();
    const head = (document.head || document.documentElement)
    head.insertBefore(s, head.firstChild);
}

injectScript('console_hider.js')