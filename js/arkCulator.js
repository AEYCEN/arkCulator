function calculateDamage(type, material) {
    const table = {
        1: {Wood:11813, Stone:99999, Metal:3544, Tek:788},
        2: {Wood:7350, Stone:99999, Metal:2205, Tek:596},
        3: {Wood:26800, Stone:14700, Metal:1450, Tek:9250},
        4: {Wood:99999, Stone:3446, Metal:355, Tek:40},
        5: {Wood:788, Stone:1838, Metal:237, Tek:53},
        6: {Wood:15750, Stone:700, Metal:0, Tek:0}
    };
    return table[type][material] || 0;
}

function calculateCost(type, amount) {
    let costs = {}
    switch (parseInt(type)) {
        case 1:
            costs = {Gunpowder:60, Crystal:10, Cement:5, Fiber:50, Hide:5, Polymer:5, Electronics:5}
            break
        case 2:
            costs = {Gunpowder:40, Crystal:10, Cement:20, Polymer:10, Metal:12}
            break
        case 4:
            costs = {Metal:80, Gunpowder:30, Cement:20, Obsidian:4}
            break
        case 5:
            costs = {Fiber:15, Stone:20, Gunpowder:30, Hide:5, Metal:2, Oil:4}
            break
        case 6:
            costs = {Stone:30, Metal:3}
            break
        default:
            costs = {}
    }

    for (let key in costs) {
        costs[key] *= amount
    }
    return costs
}

function calculate() {
    const type = document.getElementById('weapon').value
    const material = document.getElementById('material').value
    const hp = parseInt(document.getElementById('hp').value)
    const cave = document.getElementById('cave').checked

    if (isNaN(hp) || hp < 1 || hp > 100000) {
        document.getElementById('output').innerHTML = '<span style="color:red">Invalid HP input. Please enter a number between 1 and 100000.</span>'
        return
    }

    let damage = calculateDamage(type, material)
    if (damage === 0) {
        document.getElementById('output').innerHTML = 'This structure is indestructible with this weapon.'
        return
    }

    if (cave) damage *= 6

    const amount = Math.ceil(hp / damage)
    const costs = calculateCost(type, amount)

    let output = `<b>Amount needed to destroy: ${amount}</b><br><br>Resources needed to craft:`
    for (let resource in costs) {
        output += `<div class="resource">${resource}: ${costs[resource]}</div>`
    }

    document.getElementById('output').innerHTML = output
}
