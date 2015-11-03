var child_process = require('child_process'),
    fs = require('fs'),
    path = require('path'),
    rimraf = require('rimraf');


var cleanAfterBuild = function() {
  var promise = new Promise(function(resolve, reject) {
    // Check if the compiled file is here
    try {
      fs.accessSync(path.join(__dirname, '..', 'build', 'Release'));
    } catch (err) {
      console.log(err);
      reject('The compiled file is not present. Did the build fail ?')
    }

    // Then copy it to vendor
    try {
      fs.accessSync(path.join(__dirname, '..', 'vendor'));
    } catch (err) {
      fs.mkdirSync(path.join(__dirname, '..', 'vendor'));
    }
    fs.createReadStream(path.join(__dirname, '..', 'build', 'Release', 'osx-theme.node'))
      .pipe(fs.createWriteStream(path.join(__dirname, '..', 'vendor', 'osx-theme.node')));

    // And finally clean the build artefacts.
    rimraf(path.join(__dirname, '..', 'build'), function(err) {
      if (err) {
        console.log(err)
        reject('Error while removing build artefacts.');
        return;
      }

      console.log('OK.');
      resolve();
    });
  });

  return promise;
}

Promise.resolve()
  .then(function() {
    console.log('Starting the post compilation...');
    return cleanAfterBuild();
  })
  .then(function() {
    console.log('Cleaning is done !');
  })
  .catch(function(err) {
    console.log('An error happened while compiling.');
    console.log(err);
  });
