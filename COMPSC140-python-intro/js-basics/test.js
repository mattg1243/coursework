
let Matt = {

    firstName: 'Matt',
    lastName : 'Gallucci',
    age : 23,
    dob : '08-24-97'

};

let bestAlbums = [ 'MBDTF', 'College Dropout', 'DAMN', 'To Pimp a Butterfly', 'GKMC'];

console.log(Matt.firstName, Matt)
console.log(bestAlbums[0])

bestAlbums[1] = 'Yeezus'

console.log(bestAlbums.length)

function greet(message) {
    console.log(message)
}

greet('why you such a bitch')


function square(e) { 
    return e * e
};

console.log(square(3))