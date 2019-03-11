#include "webserver_files.h" 

// wegen )"; aufpassen wegen Ende von R"(
// bei Funktionsaufrufen GetArduinoIO() " <- Leerzeichen


const char *index_htm = R"(<!DOCTYPE html>
<html>
<head>
 <meta http-equiv="Content-type" content="text/html; charset=utf-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge,chrome=1" />
    <link rel="icon" href="data:;base64,iVBORw0KGgo=">
    <title>sevenSeg.js</title>
  
    <link href="//fonts.googleapis.com/css?family=Iceberg" rel="stylesheet">
    <link href="//ajax.googleapis.com/ajax/libs/jqueryui/1.10.3/themes/ui-darkness/jquery-ui.css" rel="stylesheet">   
    <link href="prettify.css" rel="stylesheet">

    <script src="//ajax.googleapis.com/ajax/libs/jquery/2.0.2/jquery.min.js"></script>
    <script src="//ajax.googleapis.com/ajax/libs/jqueryui/1.10.3/jquery-ui.min.js"></script>
    <script src="//ajax.aspnetcdn.com/ajax/knockout/knockout-2.2.1.js"></script>
    <script src="//cdnjs.cloudflare.com/ajax/libs/prettify/r224/prettify.js"></script>
    
    <script src="sevenSeg.js"></script>
    <script src="demo.js"></script>
  
    <script>
        (function (i, s, o, g, r, a, m) {
            i['GoogleAnalyticsObject'] = r; i[r] = i[r] || function () {
                (i[r].q = i[r].q || []).push(arguments)
            }, i[r].l = 1 * new Date(); a = s.createElement(o),
            m = s.getElementsByTagName(o)[0]; a.async = 1; a.src = g; m.parentNode.insertBefore(a, m)
        })(window, document, 'script', '//www.google-analytics.com/analytics.js', 'ga');

        ga('create', 'UA-44023738-2', 'brandonlwhite.github.io');
        ga('send', 'pageview');
    </script>

  <style type="text/css">
    body
    {
      margin: 0;
            font-family: "Helvetica Neue", Helvetica, Arial, sans-serif;
            font-size: 16px;
            line-height: 1.428571429;
            background-color: #DDDDDD;
      color: #333;
            background-image: url(data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAEUAAABFCAIAAACT77x+AAAAGXRFWHRTb2Z0d2FyZQBBZG9iZSBJbWFnZVJlYWR5ccllPAAAA2ZpVFh0WE1MOmNvbS5hZG9iZS54bXAAAAAAADw/eHBhY2tldCBiZWdpbj0i77u/IiBpZD0iVzVNME1wQ2VoaUh6cmVTek5UY3prYzlkIj8+IDx4OnhtcG1ldGEgeG1sbnM6eD0iYWRvYmU6bnM6bWV0YS8iIHg6eG1wdGs9IkFkb2JlIFhNUCBDb3JlIDUuMC1jMDYwIDYxLjEzNDc3NywgMjAxMC8wMi8xMi0xNzozMjowMCAgICAgICAgIj4gPHJkZjpSREYgeG1sbnM6cmRmPSJodHRwOi8vd3d3LnczLm9yZy8xOTk5LzAyLzIyLXJkZi1zeW50YXgtbnMjIj4gPHJkZjpEZXNjcmlwdGlvbiByZGY6YWJvdXQ9IiIgeG1sbnM6eG1wTU09Imh0dHA6Ly9ucy5hZG9iZS5jb20veGFwLzEuMC9tbS8iIHhtbG5zOnN0UmVmPSJodHRwOi8vbnMuYWRvYmUuY29tL3hhcC8xLjAvc1R5cGUvUmVzb3VyY2VSZWYjIiB4bWxuczp4bXA9Imh0dHA6Ly9ucy5hZG9iZS5jb20veGFwLzEuMC8iIHhtcE1NOk9yaWdpbmFsRG9jdW1lbnRJRD0ieG1wLmRpZDpGRjdGMTE3NDA3MjA2ODExOEE2REIyNzRCMzE4MEZDQSIgeG1wTU06RG9jdW1lbnRJRD0ieG1wLmRpZDo0MDJBOTUyRTMzMkYxMUUxOEEyOEIyMUM0RkExMjkyMiIgeG1wTU06SW5zdGFuY2VJRD0ieG1wLmlpZDo1REEyREQ5MjMzMkUxMUUxOEEyOEIyMUM0RkExMjkyMiIgeG1wOkNyZWF0b3JUb29sPSJBZG9iZSBQaG90b3Nob3AgQ1M1IE1hY2ludG9zaCI+IDx4bXBNTTpEZXJpdmVkRnJvbSBzdFJlZjppbnN0YW5jZUlEPSJ4bXAuaWlkOjU5MkM5NkJBMzAyMDY4MTE4QTZEQjI3NEIzMTgwRkNBIiBzdFJlZjpkb2N1bWVudElEPSJ4bXAuZGlkOkZGN0YxMTc0MDcyMDY4MTE4QTZEQjI3NEIzMTgwRkNBIi8+IDwvcmRmOkRlc2NyaXB0aW9uPiA8L3JkZjpSREY+IDwveDp4bXBtZXRhPiA8P3hwYWNrZXQgZW5kPSJyIj8+GUafGwAADVRJREFUeNps29l6HMeuhFGblgfp/Z/S99b27APyby2GWqcv+itWV2UiMQQCyOT3v/766z///PP999//999/d/Hzzz//9ddf3799/v3337vz3Xff3c2Xl5e7f8/00128vH1+//33+747f//99w8//HDX+8y9e983zl3cr3fzBrxnzHjfd78ZP3z4kAx33Zj3Vs93567vgSZqrru+73vspvjv7fPy559/3m9NmdB+7iI5/n373M378ya+n26spGnEu/njjz/e9X33QCtJlLt5d/7444+EI9DdbDGmu5v3U8LdFO50/d3bJzF6vkV696VB724rST0pMombLM0lYvfv+vPnzxTZglPYTXYPr1J67KeffrqFNUVi9f3h7ZOU9+stO0nSXSPfRZrNNRIvd0hZ93k1cqJbQ8qjiRulce9O6t/H2LoLFk5cS80xGufcwUr6cyXekZsoS96Y98Cpg/Qpl7Q9/3qRKe/RFNDczXdvprCkIUfO5oF0llh5VxNk1XvgHstWaa3F//32acaUlYIvVkVOs9z3Lbs193pDdXHf92tjvtqnmXq6J5omfeSEVg82BHeLbJ0NyotEXT/RVNF1302UoQySClptC7vvW+0Jk1oTJssQppFfLDFNAKJ035+5mVjaxbR42JU/CLMGvGDomnCCoZjxafzivl+58Y3cu/lz2FOIPqHIB94vTDcqmgBScYbWnPQtQ9gAYuF0z/zyyy95dZjRdL4bNu2Aii4AmjUXZtwvUyfnK0JwaHHm/R4KUguVIAWss9hGc27THPfkyZprpSOxwUUL0f01fQV6DVjqO3WcteUiaeriJ0W8upKQyAhZeXPf3T+ZAEMA5ZM30mhDAQN41RpSKvzM1WULmJGUjSDW71eJXnJ70vurT6WbVOhpOnMnsfL7niyoVrhv3fVWe0KUT2TAHXZXZakyaTbM4QODM9HiG3/Lkq+z8xCmF+JpNyC2PMCaZE0Tai3HkY5Iz/tB2aa+ZuHere1eRzXORyTNVLAaue9jXq/3aTr3zd8a16PIW678z9sHkEDzRghnrPY0mklBXHP1el6U6PfkDRt2JXQmys4L0Hx7hXwkYqmaFxbx6FDSh5itJ1PcRY+tFzUlzfUAdIIc+Ftk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); 
    }

      li
      {
            margin-bottom: 0.75em;
      }

      pre
      {
            font-size: 14px;
            line-height: 16px;
            text-shadow: none;
      }

      .header, .footer
      {
            background-color: #333;
            color: #999;
            text-shadow: 0px 1px 0px Black;
            font-size: 16px;
      }

      .header
      {
            padding: 0px 10px 25px 50px;
      }

      .header p
      {
            margin-top: 0;
            margin-bottom: 0;
            margin-left: 9px;
      }

      .footer
      {
            font-size: 12px;
            height: 50px;   
            margin-top: 5em;
            padding: 15px 50px 0 50px;
      }

      .footer a
      {
            color: white;
      }

    h1
    {
      font-size: 130px;
      font-family: 'Iceberg', cursive;
      margin-top: 0;
            margin-bottom: 0;
            color: #B4B4B4;
            text-shadow: 2px 2px 6px black;
    }

      h2
      {
            font-size: 26px;
            margin-top: 45px;
      }

      .content
      {
            margin-left: 50px;
            text-shadow: 0px 1px 0px #fff;
      }

    .exampleContainer
    {
      display: inline-block;
      background-color: Black;
      border-radius: 5px;
            margin-left: 18px;
            margin-right: 18px;
    }

      .exampleInput:hover
      {
            box-shadow: 0px 0px 6px 1px #B00000;
      }

      .big-sevenSeg
      {
      padding: 0.5em; 
      height: 100px; 
      width: 100px;
      }

      .med-sevenSegArray5
      {
          padding: 0.25em;
          height: 50px;
          width: 200px;
      }

      .med-sevenSegArray5Slanted
      {
          padding: 0.25em;
          height: 75px;
          width: 370px;
      }

      .resizableExample
      {
          margin: 1em;
          padding: 0.5em;
          height: 120px;
          width: 80px;
      }

      .resizableExample div:first-child
      {
          height: 100%;
      }

      pre.prettyprint
      {
            margin-left: 18px;
      }
  </style>
</head>
<body>
<div class="header">
    <h1>sevenSeg.js</h1>
    <p>A tiny JavaScript jQuery UI plugin for creating vector-based (SVG) seven-segment displays in HTML.</p>
</div>

<div class="content">
    <h2>Example</h2>
    <div class="exampleContainer">
      <div data-bind="sevenSeg: { digits: 5, value: mainExampleValue }" class="big-sevenSeg" style="width: 420px;"></div>
    </div>

    <h2>Features</h2>
    <ul>
        <li>No images. All graphics are drawn using HTML SVG that scales to any size.</li>
        <li>No external CSS file. Default style classes are injected into your page. 
            <br />If you want to tailor the style classes in your own CSS you can. 
            <br />You can also style the individual widgets via options. It's your choice.</li>
        <li>Databinders for <a href="http://knockoutjs.com/">Knockout</a> MVVM.</li>
        <li>MIT License.</li> 
    </ul>

    <h2>Usage</h2>
        Include jQuery and jQuery UI in your HTML before including sevenSeg.js.
        If you intend to use Knockout it needs to be included before sevenSeg.js too, but it's completely optional.

    <pre class="prettyprint"><xmp class="language-html">
<script src="//ajax.googleapis.com/ajax/libs/jquery/2.0.2/jquery.min.js"></script>
<script src="//ajax.googleapis.com/ajax/libs/jqueryui/1.10.3/jquery-ui.min.js"></script>
<script src="//ajax.aspnetcdn.com/ajax/knockout/knockout-2.2.1.js"></script>
<script src="sevenSeg.js"></script>
    </xmp></pre>

    <p>
        You can then instantiate <code>sevenSeg</code> widgets on any div's of your choosing.  <br />
        Each <code>sevenSeg</code> may contain any number of discrete seven-segment digits.  
        You specify the number of digits using the <code>digit</code> option.
    </p>

    <p>These are the widget options supported by <code>sevenSeg</code> (and their defaults):</p>

    <pre class="prettyprint"><code class="language-javascript">
options: {
    /**
    Defines the number of digits that comprise the array of discrete seven-segment displays.
    */
    digits: 1

    /**
    This option controls the display value on the 7seg.  Set this to the numeric value you
    want displayed.  The least significant digit will be rendered in the rightmost seven-segment digit display.
    More significant digits that exceed the limits of the number of digits you configured for the display
    will simply be omitted.
    Setting it to null will blank the display.
    */
    value: null,

    /**
    Set this to true to allow sevenSeg to respond to the mousewheel event, which
    will allow you to change the display value by spinning the mousewheel up or down.
    (The default step is +/- 1, but you can set that in the 'step' option).
    */
    allowInput: false,

    /**
    This setting controls the +/- delta value whenever the sevenSeg is incremented up or down (via mousewheel).
    The allowInput option must be true for this setting to be of use.
    */
    step: 1,

    /**
    This controls the number of decimal places displayed.  The default -1 results in no rounding and displays the value
    as-is.  A value of 0 or more defines the number of fixed decimal places that the numeric value will be rounded to.
    
    If you intend to set display values that are the result of floating point operations, including the
    use of allowInput=true and a fractional step size, then you most definitely want to set this to a specific value to
    avoid overflowing the display from floating point inaccuracies.
    */
    decimalPlaces: -1,

    /**
    Override the default segment "on" color (Red).  
    Note: You can alternatively define a CSS style for the class.sevenSeg-segOn that specifies a 'fill' color.
    */
    colorOn: null,

    /**
    Override the default segment "off" color (#320000).  
    Note: You can alternatively define a CSS style for the class .sevenSeg-svg that specifies a 'fill' color.
    */
    colorOff: null,

    /**
    Override the default background color of the display (Black).  
    Note: You can alternatively define a CSS style for the class .sevenSeg-svg that specifies a 'background-color' color.
    */
    colorBackground: null,
    
    /**
    This option allows skewing the segments to create a slant effect.
    Note: Setting "transform: skew() " in CSS is problematic for SVG. Would be nice to have, but browser support just 
    isn't there yet. So, setting the slant must be done through options.
    */
    slant: 0,  

    /**
    This flag controls the appearance of the decimal point 'dot' in the display.
    The default is to display it (true), but you can set to false to omit it.
    */
    decimalPoint: true
}   
    </code></pre>

    <h2>Basic Example</h2>
    <div class="exampleContainer">
      <div id="exampleSingle" class="big-sevenSeg"></div>
    </div>

    <pre class="prettyprint">
    // In your HTML you have something like this:
    //
    &lt;div id=&quot;example1&quot;&gt;&lt;/div&gt;

    // Then in script you simply do this. Nothing to it!
    //
    $("#example1").sevenSeg({ value: 5 });
    </pre>

    <p>Note: You will certainly want to style your div to your liking particularly the height and width.  For these examples I'm doing something like: 
        <code>padding: 0.5em; height: 100px; width: 100px;</code>
    </p>

    <h2>Multiple Digits</h2>
    <p>
        You can create arrays of seven-segment displays by specifying the <code>digits</code> option.
    </p>
    <div class="exampleContainer">
      <div id="exampleArray" class="med-sevenSegArray5"></div>
    </div>  

    <pre class="prettyprint">
    // In your HTML you have something like this:
    //
    &lt;div id=&quot;exampleArray&quot;&gt;&lt;/div&gt;

    // Then in script you can do this. 
    //
    $("#exampleArray").sevenSeg({ digits: 5, value: 12.35 });
    </pre>

    <h2>Using Knockout sevenSeg Databinding</h2>
    <p>If you are using Knockout, then it gets even easier.  Let's assume you have a View Model with a <code>testValue1</code> observable.  
        You can then use the <code>sevenSeg</code> databinding in your markup.
        (Change the value in the edit box and Knockout will keep the sevenSeg in sync).<br />
        You may notice that <em>negative numbers will render a minus symbol in the array.</em>
    </p>

    <div>
      <div class="exampleContainer">
        <div data-bind="sevenSeg: {digits: 5, value: testValue1}" class="med-sevenSegArray5"></div>
      </div>
      <input data-bind="value: testValue1, valueUpdate: 'afterkeydown'" style="width: 5em;" />
    </div>

    <pre class="prettyprint">&lt;div data-bind=&quot;sevenSeg: {digits: 5, value: testValue1}&quot;&gt;&lt;/div&gt;</pre>

    <h2>Mousewheel Input and 2-way Databinding</h2>
    <p>
        You can configure <code>sevenSeg</code> to also allow user input by setting the <code>allowInput</code> option. 
        This will cause <code>sevenSeg</code> to respond to mousewheel events in order to step the numeric value up and down.
        Additionally, you can set <code>step</code> and <code>decimalPlaces</code> if needed to achieve the desired
        numeric step size and rounding, respectively.
        <br />When used with a Knockout, this results in a two-way databinding that will update your observable with the
        new value.
    </p>
    <p>
        Go ahead and give the mousewheel a try on the <code>sevenSeg</code> below! 
        Move the mouse pointer over the display, then spin the wheel up or down.  The value will increment
        or decrement by 0.1 depending upon the direction you move the wheel.  Notice that the two-way databinding keeps the
        observable (and thus the edit box) in sync. You can still edit the value in the edit box too.
    </p>

    <div>
      <div class="exampleContainer exampleInput">
        <div data-bind="sevenSeg: { digits: 5, value: testValue2, allowInput: true, step: 0.1, decimalPlaces: 1 }" class="med-sevenSegArray5"></div>
      </div>
      <input data-bind="value: testValue2, valueUpdate: 'afterkeydown'" style="width: 12em;" />
    </div>

    <pre class="prettyprint">&lt;div data-bind=&quot;sevenSeg: { digits: 5, value: testValue2, allowInput: true, step: 0.1, decimalPlaces: 1 }&quot;&gt;&lt;/div&gt;</pre>

    <h2>Inside of a jQueryUI resizable</h2>
    <p>
    This demonstrates the dynamic sizing capabilities of sevenSeg.  In this example, a <code>sevenSeg</code>
    widget is wrapped in a jQueryUI <code><a href="http://jqueryui.com/resizable/">resizable</a></code> widget.  This allows you to pull the gripper in the corner
    to resize the display to whatever size you like.
    <br />Go ahead and give it a try!
    </p>

    <div id="testResizableDiv" class="exampleContainer resizableExample">
        <div id="testSegInsideResizable"></div>
    </div>

    <div id="testResizableDiv2" class="exampleContainer resizableExample" style="width: 275px;">
        <div id="testResizableArray"></div>
    </div>

    <h5>HTML Markup</h5>
    <pre class="prettyprint">
    &lt;div id=&quot;testResizableDiv&quot; class=&quot;exampleContainer resizableExample&quot;&gt;
        &lt;div id=&quot;testSegInsideResizable&quot;&gt;&lt;/div&gt;
    &lt;/div&gt;
    &lt;div id=&quot;testResizableDiv2&quot; class=&quot;exampleContainer resizableExample&quot; style=&quot;width: 275px;&quot;&gt;
        &lt;div id=&quot;testResizableArray&quot;&gt;&lt;/div&gt;
    &lt;/div&gt;</pre>

    <h5>CSS</h5>
    <pre class="prettyprint">
    .exampleContainer
    {
        display: inline-block;
        background-color: Black;
        border-radius: 5px;
        margin-left: 12px;
    }

    .resizableExample
    {
        margin: 1em;
        padding: 0.5em;
        height: 120px;
        width: 80px;
    }

    .resizableExample div:first-child
    {
        height: 100%;
    }
    </pre>    

    <h5>Script</h5>
    <pre class="prettyprint">
    $("#testResizableDiv").resizable({ aspectRatio: true });
    $("#testSegInsideResizable").sevenSeg({ value: 8 });

    $("#testResizableArray").sevenSeg({ digits: 3 });
    $("#testResizableDiv2").resizable({ aspectRatio: true });

    var iArrayValue = 0;
    setInterval(function() {
        $("#testResizableArray").sevenSeg({ value: iArrayValue });
        if(++iArrayValue > 999) { 
            iArrayValue = 0; 
        }
    }, 50);
    </pre>

    <h2>Full Page sevenSeg</h2>
    Click <a href="fullPage.html" target="_blank">this link</a> to view a full-page sevenSeg demonstration.
    <br />Put your browser in full-screen mode and voil&agrave;, DIY scoreboard!

    <h2>Customizing Options</h2>
    <div class="exampleContainer">
      <div id="testArray1" class="med-sevenSegArray5Slanted"></div>
    </div>
    <p>This sevenSeg was created with the following options:</p>

    <pre class="prettyprint">
    $("#testArray1").sevenSeg({
        digits:5, 
        value:-98.76, 
        colorOff: "#003200", 
        colorOn: "Lime", 
        slant: 10
    });
    </pre>

    <h2>jQuery UI Widget Create and Destroy</h2>
    <button id="btnCreate">Create</button>
    <button id="btnDestroy">Destroy</button>
    <div id="testArray2" class="med-sevenSegArray5"></div>

    <h2>Whole Lotta Seven-Segment Displays</h2>
    <div class="exampleContainer" style="padding-right: 5px;">
        <div data-bind="sevenSeg: { digits: 50, value: '2727653170286030230.4546439762795232493021364947166' }" 
             class="med-sevenSegArray5" style="width: 100%">
        </div>
    </div>
    <pre class="prettyprint">
    &lt;div data-bind=&quot;sevenSeg: { digits: 50, value: '2727653170286030230.4546439762795232493021364947166' }&quot;&gt;&lt;/div&gt;</pre>
    <p>Sheesh! That's more than you can shake a stick at.  Notice that this insane number has actually been passed as a string.</p>
</div>

<div class="footer">
    <div style="float: left;">        
        sevenSeg.js is released under the <a href="MIT-LICENSE.txt">MIT License</a>.
        Copyright &copy; 2013 Brandon L White.
    </div>
    <div style="float: right;">
        Source code available on <a href="https://github.com/BrandonLWhite/sevenSeg.js">Github</a>
    </div>
</div>

<a href="https://github.com/BrandonLWhite/sevenSeg.js"><img style="position: absolute; top: 0; right: 0; border: 0;" src="https://s3.amazonaws.com/github/ribbons/forkme_right_red_aa0000.png" alt="Fork me on GitHub"></a>
</body>
</html>
)";
