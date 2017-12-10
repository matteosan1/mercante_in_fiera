pragma Singleton
import QtQuick 2.0

QtObject { // Use Theme instead of QtObject
    property int carteScoperte: 0

    // Bind the `Theme`s properties as intermediate variables to the current Theme.
    //color0: (current && current.color0 ? current.color0 : 'defaultColor0')
    //color1: (current && current.color1 ? current.color1 : 'defaultColor1')
    //colorX: (current && current.colorX ? current.colorX : 'defaultColorX')
}
