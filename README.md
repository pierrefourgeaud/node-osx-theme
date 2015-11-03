# node-osx-theme
Retreive information about the theme on OSX through a light and easy to use API.

Not executing external binary :)

**Requires OS X 10.10 or later.**

**Manage `System Preferences` → `General` → `Use dark menu bar and Dock`.**

## Install

```sh
$ npm install --save osx-theme
```

## API

### theme.getMode()

Returns `'Light'` or `'Dark'` depending what theme is activated.

### theme.setMode(mode)

Set the mode you want.
Possible values are `'Light'` or `'Dark'`. Is you make a typo, `'Light'` will be used.

### theme.toggleMode()

Toggle the theme you are on.

### theme.isDark()

Returns `true` if the theme is dark, `false` otherwise.

### theme.isLight()

Returns `true` if the theme is light, `false` otherwise.

## Example

```js
var theme = require('osx-theme');

console.log(theme.isDark()) // True if the dark mode is activated, false otherwise

console.log(theme.isLight()) // True if the light mode is activated, false otherwise

console.log(theme.getMode()) // 'Light' or 'Dark'

theme.setMode('Light') // or 'Dark'

theme.toggleMode() // easy to understand :)
```

## Support

* Bugs and feature requests: [Github issue tracker](https://github.com/pierrefourgeaud/node-osx-theme/issues?state=open)

## License

The MIT License (MIT)

Copyright (c) 2014 Pierre Fourgeaud

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
