
---
This is [an example](http://example.com/ "Title") inline link.

[This link](http://example.net/) has no title attribute.

<p>This is <a href="http://example.com/" title="Title">
an example</a> inline link.</p>

<p><a href="http://example.net/">This link</a> has no
title attribute.</p>

See my [About](/about/) page for details. 

This is [an example][id] reference-style link.

This is an example [id] reference-style link.

[id]: http://example.com/  "Optional Title Here"

[foo]: http://example.com/  "Optional Title Here"
[foo]: http://example.com/  'Optional Title Here'
[foo]: http://example.com/  (Optional Title Here)

[id]: <http://example.com/>  "Optional Title Here"

[id]: http://example.com/longish/path/to/resource/here
    "Optional Title Here"

[link text][a]
[link text][A]

[Google][]

[Google]: http://google.com/

Visit [Daring Fireball][] for more information.

[Daring Fireball]: http://daringfireball.net/

I get 10 times more traffic from [Google][1] than from
[Yahoo][2] or [MSN][3].

  [1]: http://google.com/        "Google"
  [2]: http://search.yahoo.com/  "Yahoo Search"
  [3]: http://search.msn.com/    "MSN Search"

I get 10 times more traffic from [Google][] than from
[Yahoo][] or [MSN][].

  [google]: http://google.com/        "Google"
  [yahoo]:  http://search.yahoo.com/  "Yahoo Search"
  [msn]:    http://search.msn.com/    "MSN Search"

I get 10 times more traffic from [Google](http://google.com/ "Google")
than from [Yahoo](http://search.yahoo.com/ "Yahoo Search") or
[MSN](http://search.msn.com/ "MSN Search").