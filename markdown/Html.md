Markdown’s syntax is intended for one purpose: to be used as a format for writing for the web.

Markdown is not a replacement for HTML, or even close to it. Its syntax is very small, corresponding only to a very small subset of HTML tags. The idea is not to create a syntax that makes it easier to insert HTML tags. In my opinion, HTML tags are already easy to insert. The idea for Markdown is to make it easy to read, write, and edit prose. HTML is a publishing format; Markdown is a writing format. Thus, Markdown’s formatting syntax only addresses issues that can be conveyed in plain text.

For any markup that is not covered by Markdown’s syntax, you simply use HTML itself. There’s no need to preface it or delimit it to indicate that you’re switching from Markdown to HTML; you just use the tags.

> normal

Note that Markdown formatting syntax is not processed within block-level HTML tags. E.g., you can’t use Markdown-style *emphasis* inside an HTML block.

<table>
    <tr>
        <td>row1 col1</td>
        <td>row2 col2</td>
    </tr>
    <tr>
        <td>row2 col1</td>
        <td>row2 col2</td>
    </tr>
        <tr>
        <td>row3 col1</td>
        <td>*useless emphasis*</td>
    </tr>
</table>
<div margin="18px">
    <p>margin is useless</p>
</div>
<p><a>http://www.google.com</a></p>

<div>
    <p>&lt;&gt;&amp;</p>
    <p><a>http://images.google.com/images?num=30&amp;q=larry+bird</a></p>
    <p>&copy;</p>
</div>
<br/><br />

The only restrictions are that block-level HTML elements — e.g. &lt;div&gt;, <&lt;able&gt;, &lt;pre&gt;, &lt;p&gt;, etc. — must be separated from surrounding content by blank lines, and the start and end tags of the block should not be indented with tabs or spaces. Markdown is smart enough not to add extra (unwanted) <p> tags around HTML block-level tags.

> tab prefixed

    <table>
        <tr>
            <td>row1 col1</td>
            <td>row2 col2</td>
        </tr>
        <tr>
            <td>row2 col1</td>
            <td>row2col2</td>
        </tr>
    </table>
