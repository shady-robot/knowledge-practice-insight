# markdown

Markdown is a text-to-HTML conversion tool for web writers. Markdown allows
you to write using an easy-to-read, easy-to-write plain text format, then
convert it to structurally valid XHTML (or HTML).

## Basic Syntax

Refer to [Markdown Basic Syntax][basic syntax] for basic usage.

## Link to part of the same document

To create inner document links in markdown in Github use the following syntax,
since Github automatically parses anchor tags out of your headers.

### Syntax

* Use one \# for all heading sizes
* No space between \# and anchor name
* Anchor tag names must be lowercase, and delimited by dashes if multi-word

```markdown
# Contents
 - [Specification](#specification)
 - [Dependencies Title](#dependencies-title)

## Specification
Example text blah. Example text blah. Example text blah. Example text blah.
Example text blah. Example text blah. Example text blah. Example text blah.
Example text blah. Example text blah. Example text blah. Example text blah.
Example text blah. Example text blah.

## Dependencies Title
Example text blah. Example text blah. Example text blah. Example text blah.
Example text blah. Example text blah. Example text blah. Example text blah.
Example text blah. Example text blah. Example text blah. Example text blah.
Example text blah. Example text blah.
```

## Collapsible section containing

<details>
  <summary>Click to expand!</summary>

    ### Heading

    1. A numbered
    2. list
      * With some
      * Sub bullets

</details>

How to structure:

```html
# A collapsible section with markdown
<details>
  <summary>Click to expand!</summary>

  ## Heading
  1. A numbered
  2. list
     * With some
     * Sub bullets
</details>
```

## Markdown lint tool

A tool to check markdown files and flag style issues.

## References

* [A collapsible section containing markdown][collapsible]
* [Link to part of the same document][link-to-part]
* [markdown lint][linter]

[basic syntax]: https://www.markdownguide.org/basic-syntax/
[collapsible]: https://gist.github.com/pierrejoubert73/902cc94d79424356a8d20be2b382e1ab
[link-to-part]: https://stackoverflow.com/questions/2822089/how-to-link-to-part-of-the-same-document-in-markdown
[linter]: https://github.com/markdownlint/markdownlint