d3 = function() {
    function o(e) {
        return e != null && !isNaN(e);
    }
    function a(e) {
        return e.length;
    }
    function f(e) {
        var t = 1;
        while (e * t % 1) t *= 10;
        return t;
    }
    function l(e, t) {
        try {
            for (var n in t) Object.defineProperty(e.prototype, n, {
                value: t[n],
                enumerable: !1
            });
        } catch (r) {
            e.prototype = t;
        }
    }
    function c() {}
    function d() {}
    function v(e, t, n) {
        return function() {
            var r = n.apply(t, arguments);
            return r === t ? e : r;
        };
    }
    function m() {}
    function g(e) {
        function r() {
            var n = t, r = -1, i = n.length, s;
            while (++r < i) (s = n[r].on) && s.apply(this, arguments);
            return e;
        }
        var t = [], n = new c;
        r.on = function(r, i) {
            var s = n.get(r), o;
            if (arguments.length < 2) return s && s.on;
            if (s) {
                s.on = null;
                t = t.slice(0, o = t.indexOf(s)).concat(t.slice(o + 1));
                n.remove(r);
            }
            i && t.push(n.set(r, {
                on: i
            }));
            return e;
        };
        return r;
    }
    function y() {
        e.event.stopPropagation();
        e.event.preventDefault();
    }
    function w() {
        var t = e.event, n;
        while (n = t.sourceEvent) t = n;
        return t;
    }
    function E(e, t) {
        function n() {
            e.on(t, null);
        }
        e.on(t, function() {
            y();
            n();
        }, !0);
        setTimeout(n, 0);
    }
    function S(t) {
        var n = new m, r = 0, i = arguments.length;
        while (++r < i) n[arguments[r]] = g(n);
        n.of = function(r, i) {
            return function(s) {
                try {
                    var o = s.sourceEvent = e.event;
                    s.target = t;
                    e.event = s;
                    n[s.type].apply(r, i);
                } finally {
                    e.event = o;
                }
            };
        };
        return n;
    }
    function T(r, i) {
        var s = r.ownerSVGElement || r;
        if (s.createSVGPoint) {
            var o = s.createSVGPoint();
            if (x < 0 && (n.scrollX || n.scrollY)) {
                s = e.select(t.body).append("svg").style("position", "absolute").style("top", 0).style("left", 0);
                var u = s[0][0].getScreenCTM();
                x = !u.f && !u.e;
                s.remove();
            }
            if (x) {
                o.x = i.pageX;
                o.y = i.pageY;
            } else {
                o.x = i.clientX;
                o.y = i.clientY;
            }
            o = o.matrixTransform(r.getScreenCTM().inverse());
            return [ o.x, o.y ];
        }
        var a = r.getBoundingClientRect();
        return [ i.clientX - a.left - r.clientLeft, i.clientY - a.top - r.clientTop ];
    }
    function C(e) {
        var t = -1, n = e.length, r = [];
        while (++t < n) r.push(e[t]);
        return r;
    }
    function k(e) {
        return Array.prototype.slice.call(e);
    }
    function O(e) {
        A(e, B);
        return e;
    }
    function j(e) {
        return function() {
            return M(e, this);
        };
    }
    function F(e) {
        return function() {
            return _(e, this);
        };
    }
    function q(t, n) {
        function r() {
            this.removeAttribute(t);
        }
        function i() {
            this.removeAttributeNS(t.space, t.local);
        }
        function s() {
            this.setAttribute(t, n);
        }
        function o() {
            this.setAttributeNS(t.space, t.local, n);
        }
        function u() {
            var e = n.apply(this, arguments);
            e == null ? this.removeAttribute(t) : this.setAttribute(t, e);
        }
        function a() {
            var e = n.apply(this, arguments);
            e == null ? this.removeAttributeNS(t.space, t.local) : this.setAttributeNS(t.space, t.local, e);
        }
        t = e.ns.qualify(t);
        return n == null ? t.local ? i : r : typeof n == "function" ? t.local ? a : u : t.local ? o : s;
    }
    function R(e) {
        return e.trim().replace(/\s+/g, " ");
    }
    function z(t) {
        return new RegExp("(?:^|\\s+)" + e.requote(t) + "(?:\\s+|$)", "g");
    }
    function W(e, t) {
        function r() {
            var r = -1;
            while (++r < n) e[r](this, t);
        }
        function i() {
            var r = -1, i = t.apply(this, arguments);
            while (++r < n) e[r](this, i);
        }
        e = e.trim().split(/\s+/).map(X);
        var n = e.length;
        return typeof t == "function" ? i : r;
    }
    function X(e) {
        var t = z(e);
        return function(n, r) {
            if (i = n.classList) return r ? i.add(e) : i.remove(e);
            var i = n.getAttribute("class") || "";
            if (r) {
                t.lastIndex = 0;
                t.test(i) || n.setAttribute("class", R(i + " " + e));
            } else n.setAttribute("class", R(i.replace(t, " ")));
        };
    }
    function V(e, t, n) {
        function r() {
            this.style.removeProperty(e);
        }
        function i() {
            this.style.setProperty(e, t, n);
        }
        function s() {
            var r = t.apply(this, arguments);
            r == null ? this.style.removeProperty(e) : this.style.setProperty(e, r, n);
        }
        return t == null ? r : typeof t == "function" ? s : i;
    }
    function $(e, t) {
        function n() {
            delete this[e];
        }
        function r() {
            this[e] = t;
        }
        function i() {
            var n = t.apply(this, arguments);
            n == null ? delete this[e] : this[e] = n;
        }
        return t == null ? n : typeof t == "function" ? i : r;
    }
    function J(e) {
        return {
            __data__: e
        };
    }
    function K(e) {
        return function() {
            return H(this, e);
        };
    }
    function Q(t) {
        arguments.length || (t = e.ascending);
        return function(e, n) {
            return !e - !n || t(e.__data__, n.__data__);
        };
    }
    function G() {}
    function Y(t, n, r) {
        function a() {
            var e = this[i];
            if (e) {
                this.removeEventListener(t, e, e.$);
                delete this[i];
            }
        }
        function f() {
            var e = o(n, N(arguments));
            a.call(this);
            this.addEventListener(t, this[i] = e, e.$ = r);
            e._ = n;
        }
        function l() {
            var n = new RegExp("^__on([^.]+)" + e.requote(t) + "$"), r;
            for (var i in this) if (r = i.match(n)) {
                var s = this[i];
                this.removeEventListener(r[1], s, s.$);
                delete this[i];
            }
        }
        var i = "__on" + t, s = t.indexOf("."), o = et;
        s > 0 && (t = t.substring(0, s));
        var u = Z.get(t);
        u && (t = u, o = tt);
        return s ? n ? f : a : n ? G : l;
    }
    function et(t, n) {
        return function(r) {
            var i = e.event;
            e.event = r;
            n[0] = this.__data__;
            try {
                t.apply(this, n);
            } finally {
                e.event = i;
            }
        };
    }
    function tt(e, t) {
        var n = et(e, t);
        return function(e) {
            var t = this, r = e.relatedTarget;
            (!r || r !== t && !(r.compareDocumentPosition(t) & 8)) && n.call(t, e);
        };
    }
    function nt(e, t) {
        for (var n = 0, r = e.length; n < r; n++) for (var i = e[n], s = 0, o = i.length, u; s < o; s++) (u = i[s]) && t(u, s, n);
        return e;
    }
    function rt(e) {
        A(e, it);
        return e;
    }
    function ft() {}
    function lt(e, t, n) {
        return new ct(e, t, n);
    }
    function ct(e, t, n) {
        this.h = e;
        this.s = t;
        this.l = n;
    }
    function pt(e, t, n) {
        function s(e) {
            e > 360 ? e -= 360 : e < 0 && (e += 360);
            return e < 60 ? r + (i - r) * e / 60 : e < 180 ? i : e < 240 ? r + (i - r) * (240 - e) / 60 : r;
        }
        function o(e) {
            return Math.round(s(e) * 255);
        }
        var r, i;
        e %= 360;
        e < 0 && (e += 360);
        t = t < 0 ? 0 : t > 1 ? 1 : t;
        n = n < 0 ? 0 : n > 1 ? 1 : n;
        i = n <= .5 ? n * (1 + t) : n + t - n * t;
        r = 2 * n - i;
        return qt(o(e + 120), o(e), o(e - 120));
    }
    function yt(e) {
        return e > 0 ? 1 : e < 0 ? -1 : 0;
    }
    function bt(e) {
        return Math.acos(Math.max(-1, Math.min(1, e)));
    }
    function wt(e) {
        return e > 1 ? dt / 2 : e < -1 ? -dt / 2 : Math.asin(e);
    }
    function Et(e) {
        return (Math.exp(e) - Math.exp(-e)) / 2;
    }
    function St(e) {
        return (Math.exp(e) + Math.exp(-e)) / 2;
    }
    function xt(e) {
        return (e = Math.sin(e / 2)) * e;
    }
    function Tt(e, t, n) {
        return new Nt(e, t, n);
    }
    function Nt(e, t, n) {
        this.h = e;
        this.c = t;
        this.l = n;
    }
    function kt(e, t, n) {
        return Lt(n, Math.cos(e *= mt) * t, Math.sin(e) * t);
    }
    function Lt(e, t, n) {
        return new At(e, t, n);
    }
    function At(e, t, n) {
        this.l = e;
        this.a = t;
        this.b = n;
    }
    function Ht(e, t, n) {
        var r = (e + 16) / 116, i = r + t / 500, s = r - n / 200;
        i = jt(i) * Mt;
        r = jt(r) * _t;
        s = jt(s) * Dt;
        return qt(It(3.2404542 * i - 1.5371385 * r - .4985314 * s), It(-0.969266 * i + 1.8760108 * r + .041556 * s), It(.0556434 * i - .2040259 * r + 1.0572252 * s));
    }
    function Bt(e, t, n) {
        return Tt(Math.atan2(n, t) * gt, Math.sqrt(t * t + n * n), e);
    }
    function jt(e) {
        return e > .206893034 ? e * e * e : (e - 4 / 29) / 7.787037;
    }
    function Ft(e) {
        return e > .008856 ? Math.pow(e, 1 / 3) : 7.787037 * e + 4 / 29;
    }
    function It(e) {
        return Math.round(255 * (e <= .00304 ? 12.92 * e : 1.055 * Math.pow(e, 1 / 2.4) - .055));
    }
    function qt(e, t, n) {
        return new Rt(e, t, n);
    }
    function Rt(e, t, n) {
        this.r = e;
        this.g = t;
        this.b = n;
    }
    function zt(e) {
        return e < 16 ? "0" + Math.max(0, e).toString(16) : Math.min(255, e).toString(16);
    }
    function Wt(e, t, n) {
        var r = 0, i = 0, s = 0, o, u, a;
        o = /([a-z]+)\((.*)\)/i.exec(e);
        if (o) {
            u = o[2].split(",");
            switch (o[1]) {
              case "hsl":
                return n(parseFloat(u[0]), parseFloat(u[1]) / 100, parseFloat(u[2]) / 100);
              case "rgb":
                return t(Jt(u[0]), Jt(u[1]), Jt(u[2]));
            }
        }
        if (a = Kt.get(e)) return t(a.r, a.g, a.b);
        if (e != null && e.charAt(0) === "#") {
            if (e.length === 4) {
                r = e.charAt(1);
                r += r;
                i = e.charAt(2);
                i += i;
                s = e.charAt(3);
                s += s;
            } else if (e.length === 7) {
                r = e.substring(1, 3);
                i = e.substring(3, 5);
                s = e.substring(5, 7);
            }
            r = parseInt(r, 16);
            i = parseInt(i, 16);
            s = parseInt(s, 16);
        }
        return t(r, i, s);
    }
    function Xt(e, t, n) {
        var r = Math.min(e /= 255, t /= 255, n /= 255), i = Math.max(e, t, n), s = i - r, o, u, a = (i + r) / 2;
        if (s) {
            u = a < .5 ? s / (i + r) : s / (2 - i - r);
            e == i ? o = (t - n) / s + (t < n ? 6 : 0) : t == i ? o = (n - e) / s + 2 : o = (e - t) / s + 4;
            o *= 60;
        } else u = o = 0;
        return lt(o, u, a);
    }
    function Vt(e, t, n) {
        e = $t(e);
        t = $t(t);
        n = $t(n);
        var r = Ft((.4124564 * e + .3575761 * t + .1804375 * n) / Mt), i = Ft((.2126729 * e + .7151522 * t + .072175 * n) / _t), s = Ft((.0193339 * e + .119192 * t + .9503041 * n) / Dt);
        return Lt(116 * i - 16, 500 * (r - i), 200 * (i - s));
    }
    function $t(e) {
        return (e /= 255) <= .04045 ? e / 12.92 : Math.pow((e + .055) / 1.055, 2.4);
    }
    function Jt(e) {
        var t = parseFloat(e);
        return e.charAt(e.length - 1) === "%" ? Math.round(t * 2.55) : t;
    }
    function Qt(e) {
        return typeof e == "function" ? e : function() {
            return e;
        };
    }
    function Gt(e) {
        return e;
    }
    function Yt(e) {
        return e.length === 1 ? function(t, n) {
            e(t == null ? n : null);
        } : e;
    }
    function Zt(t, n) {
        function s(t, r, i) {
            arguments.length < 3 && (i = r, r = null);
            var s = e.xhr(t, n, i);
            s.row = function(e) {
                return arguments.length ? s.response((r = e) == null ? o : u(e)) : r;
            };
            return s.row(r);
        }
        function o(e) {
            return s.parse(e.responseText);
        }
        function u(e) {
            return function(t) {
                return s.parse(t.responseText, e);
            };
        }
        function a(e) {
            return e.map(f).join(t);
        }
        function f(e) {
            return r.test(e) ? '"' + e.replace(/\"/g, '""') + '"' : e;
        }
        var r = new RegExp('["' + t + "\n]"), i = t.charCodeAt(0);
        s.parse = function(e, t) {
            var n;
            return s.parseRows(e, function(e, r) {
                if (n) return n(e, r - 1);
                var i = new Function("d", "return {" + e.map(function(e, t) {
                    return JSON.stringify(e) + ": d[" + t + "]";
                }).join(",") + "}");
                n = t ? function(e, n) {
                    return t(i(e), n);
                } : i;
            });
        };
        s.parseRows = function(e, t) {
            function c() {
                if (u >= o) return r;
                if (l) return l = !1, n;
                var t = u;
                if (e.charCodeAt(t) === 34) {
                    var s = t;
                    while (s++ < o) if (e.charCodeAt(s) === 34) {
                        if (e.charCodeAt(s + 1) !== 34) break;
                        ++s;
                    }
                    u = s + 2;
                    var a = e.charCodeAt(s + 1);
                    if (a === 13) {
                        l = !0;
                        e.charCodeAt(s + 2) === 10 && ++u;
                    } else a === 10 && (l = !0);
                    return e.substring(t + 1, s).replace(/""/g, '"');
                }
                while (u < o) {
                    var a = e.charCodeAt(u++), f = 1;
                    if (a === 10) l = !0; else if (a === 13) {
                        l = !0;
                        e.charCodeAt(u) === 10 && (++u, ++f);
                    } else if (a !== i) continue;
                    return e.substring(t, u - f);
                }
                return e.substring(t);
            }
            var n = {}, r = {}, s = [], o = e.length, u = 0, a = 0, f, l;
            while ((f = c()) !== r) {
                var h = [];
                while (f !== n && f !== r) {
                    h.push(f);
                    f = c();
                }
                if (t && !(h = t(h, a++))) continue;
                s.push(h);
            }
            return s;
        };
        s.format = function(e) {
            if (Array.isArray(e[0])) return s.formatRows(e);
            var n = new d, r = [];
            e.forEach(function(e) {
                for (var t in e) n.has(t) || r.push(n.add(t));
            });
            return [ r.map(f).join(t) ].concat(e.map(function(e) {
                return r.map(function(t) {
                    return f(e[t]);
                }).join(t);
            })).join("\n");
        };
        s.formatRows = function(e) {
            return e.map(a).join("\n");
        };
        return s;
    }
    function on() {
        var e, t = Date.now(), n = nn;
        while (n) {
            e = t - n.then;
            e >= n.delay && (n.flush = n.callback(e));
            n = n.next;
        }
        var r = un() - t;
        if (r > 24) {
            if (isFinite(r)) {
                clearTimeout(sn);
                sn = setTimeout(on, r);
            }
            rn = 0;
        } else {
            rn = 1;
            an(on);
        }
    }
    function un() {
        var e = null, t = nn, n = Infinity;
        while (t) if (t.flush) {
            delete tn[t.callback.id];
            t = e ? e.next = t.next : nn = t.next;
        } else {
            n = Math.min(n, t.then + t.delay);
            t = (e = t).next;
        }
        return n;
    }
    function pn(e, t) {
        var n = Math.pow(10, Math.abs(8 - t) * 3);
        return {
            scale: t > 8 ? function(e) {
                return e / n;
            } : function(e) {
                return e * n;
            },
            symbol: e
        };
    }
    function mn(e, t) {
        return t - (e ? Math.ceil(Math.log(e) / Math.LN10) : 1);
    }
    function gn(e) {
        return e + "";
    }
    function wn(e, t) {
        e && Sn.hasOwnProperty(e.type) && Sn[e.type](e, t);
    }
    function xn(e, t, n) {
        var r = -1, i = e.length - n, s;
        t.lineStart();
        while (++r < i) s = e[r], t.point(s[0], s[1]);
        t.lineEnd();
    }
    function Tn(e, t) {
        var n = -1, r = e.length;
        t.polygonStart();
        while (++n < r) xn(e[n], t, 1);
        t.polygonEnd();
    }
    function An() {
        function s(e, t) {
            e *= mt;
            t = t * mt / 2 + dt / 4;
            var s = e - n, o = Math.cos(t), u = Math.sin(t), a = i * u, f = Cn, l = kn, c = r * o + a * Math.cos(s), h = a * Math.sin(s);
            Cn = f * c - l * h;
            kn = l * c + f * h;
            n = e, r = o, i = u;
        }
        var e, t, n, r, i;
        Ln.point = function(o, u) {
            Ln.point = s;
            n = (e = o) * mt, r = Math.cos(u = (t = u) * mt / 2 + dt / 4), i = Math.sin(u);
        };
        Ln.lineEnd = function() {
            s(e, t);
        };
    }
    function On(t) {
        function u(e, t) {
            e < n && (n = e);
            e > i && (i = e);
            t < r && (r = t);
            t > s && (s = t);
        }
        function a() {
            o.point = o.lineEnd = G;
        }
        var n, r, i, s, o = {
            point: u,
            lineStart: G,
            lineEnd: G,
            polygonStart: function() {
                o.lineEnd = a;
            },
            polygonEnd: function() {
                o.point = u;
            }
        };
        return function(u) {
            s = i = -(n = r = Infinity);
            e.geo.stream(u, t(o));
            return [ [ n, r ], [ i, s ] ];
        };
    }
    function jn(e, t) {
        if (Mn) return;
        ++_n;
        e *= mt;
        var n = Math.cos(t *= mt);
        Dn += (n * Math.cos(e) - Dn) / _n;
        Pn += (n * Math.sin(e) - Pn) / _n;
        Hn += (Math.sin(t) - Hn) / _n;
    }
    function Fn() {
        var e, t;
        Mn = 1;
        In();
        Mn = 2;
        var n = Bn.point;
        Bn.point = function(r, i) {
            n(e = r, t = i);
        };
        Bn.lineEnd = function() {
            Bn.point(e, t);
            qn();
            Bn.lineEnd = qn;
        };
    }
    function In() {
        function r(r, i) {
            r *= mt;
            var s = Math.cos(i *= mt), o = s * Math.cos(r), u = s * Math.sin(r), a = Math.sin(i), f = Math.atan2(Math.sqrt((f = t * a - n * u) * f + (f = n * o - e * a) * f + (f = e * u - t * o) * f), e * o + t * u + n * a);
            _n += f;
            Dn += f * (e + (e = o));
            Pn += f * (t + (t = u));
            Hn += f * (n + (n = a));
        }
        var e, t, n;
        if (Mn > 1) return;
        if (Mn < 1) {
            Mn = 1;
            _n = Dn = Pn = Hn = 0;
        }
        Bn.point = function(i, s) {
            i *= mt;
            var o = Math.cos(s *= mt);
            e = o * Math.cos(i);
            t = o * Math.sin(i);
            n = Math.sin(s);
            Bn.point = r;
        };
    }
    function qn() {
        Bn.point = jn;
    }
    function Rn(e) {
        var t = e[0], n = e[1], r = Math.cos(n);
        return [ r * Math.cos(t), r * Math.sin(t), Math.sin(n) ];
    }
    function Un(e, t) {
        return e[0] * t[0] + e[1] * t[1] + e[2] * t[2];
    }
    function zn(e, t) {
        return [ e[1] * t[2] - e[2] * t[1], e[2] * t[0] - e[0] * t[2], e[0] * t[1] - e[1] * t[0] ];
    }
    function Wn(e, t) {
        e[0] += t[0];
        e[1] += t[1];
        e[2] += t[2];
    }
    function Xn(e, t) {
        return [ e[0] * t, e[1] * t, e[2] * t ];
    }
    function Vn(e) {
        var t = Math.sqrt(e[0] * e[0] + e[1] * e[1] + e[2] * e[2]);
        e[0] /= t;
        e[1] /= t;
        e[2] /= t;
    }
    function $n() {
        return !0;
    }
    function Jn(e) {
        return [ Math.atan2(e[1], e[0]), Math.asin(Math.max(-1, Math.min(1, e[2]))) ];
    }
    function Kn(e, t) {
        return Math.abs(e[0] - t[0]) < vt && Math.abs(e[1] - t[1]) < vt;
    }
    function Qn(e, t, n, r, i) {
        var s = [], o = [];
        e.forEach(function(e) {
            if ((t = e.length - 1) <= 0) return;
            var t, n = e[0], r = e[t];
            if (Kn(n, r)) {
                i.lineStart();
                for (var u = 0; u < t; ++u) i.point((n = e[u])[0], n[1]);
                i.lineEnd();
                return;
            }
            var a = {
                point: n,
                points: e,
                other: null,
                visited: !1,
                entry: !0,
                subject: !0
            }, f = {
                point: n,
                points: [ n ],
                other: a,
                visited: !1,
                entry: !1,
                subject: !1
            };
            a.other = f;
            s.push(a);
            o.push(f);
            a = {
                point: r,
                points: [ r ],
                other: null,
                visited: !1,
                entry: !1,
                subject: !0
            };
            f = {
                point: r,
                points: [ r ],
                other: a,
                visited: !1,
                entry: !0,
                subject: !1
            };
            a.other = f;
            s.push(a);
            o.push(f);
        });
        o.sort(t);
        Gn(s);
        Gn(o);
        if (!s.length) return;
        if (n) for (var u = 1, a = !n(o[0].point), f = o.length; u < f; ++u) o[u].entry = a = !a;
        var l = s[0], c, h, p;
        for (;;) {
            c = l;
            while (c.visited) if ((c = c.next) === l) return;
            h = c.points;
            i.lineStart();
            do {
                c.visited = c.other.visited = !0;
                if (c.entry) {
                    if (c.subject) for (var u = 0; u < h.length; u++) i.point((p = h[u])[0], p[1]); else r(c.point, c.next.point, 1, i);
                    c = c.next;
                } else {
                    if (c.subject) {
                        h = c.prev.points;
                        for (var u = h.length; --u >= 0; ) i.point((p = h[u])[0], p[1]);
                    } else r(c.point, c.prev.point, -1, i);
                    c = c.prev;
                }
                c = c.other;
                h = c.points;
            } while (!c.visited);
            i.lineEnd();
        }
    }
    function Gn(e) {
        if (!(t = e.length)) return;
        var t, n = 0, r = e[0], i;
        while (++n < t) {
            r.next = i = e[n];
            i.prev = r;
            r = i;
        }
        r.next = i = e[0];
        i.prev = r;
    }
    function Yn(t, n, r) {
        return function(i) {
            function u(e, n) {
                t(e, n) && i.point(e, n);
            }
            function a(e, t) {
                s.point(e, t);
            }
            function f() {
                o.point = a;
                s.lineStart();
            }
            function l() {
                o.point = u;
                s.lineEnd();
            }
            function y(e, t) {
                m.point(e, t);
                g.push([ e, t ]);
            }
            function b() {
                m.lineStart();
                g = [];
            }
            function w() {
                y(g[0][0], g[0][1]);
                m.lineEnd();
                var e = m.clean(), t = v.buffer(), n, r = t.length;
                if (!r) {
                    d = !0;
                    p += tr(g, -1);
                    g = null;
                    return;
                }
                g = null;
                if (e & 1) {
                    n = t[0];
                    h += tr(n, 1);
                    var r = n.length - 1, s = -1, o;
                    i.lineStart();
                    while (++s < r) i.point((o = n[s])[0], o[1]);
                    i.lineEnd();
                    return;
                }
                r > 1 && e & 2 && t.push(t.pop().concat(t.shift()));
                c.push(t.filter(Zn));
            }
            var s = n(i), o = {
                point: u,
                lineStart: f,
                lineEnd: l,
                polygonStart: function() {
                    o.point = y;
                    o.lineStart = b;
                    o.lineEnd = w;
                    d = !1;
                    p = h = 0;
                    c = [];
                    i.polygonStart();
                },
                polygonEnd: function() {
                    o.point = u;
                    o.lineStart = f;
                    o.lineEnd = l;
                    c = e.merge(c);
                    if (c.length) Qn(c, nr, null, r, i); else if (h < -vt || d && p < -vt) {
                        i.lineStart();
                        r(null, null, 1, i);
                        i.lineEnd();
                    }
                    i.polygonEnd();
                    c = null;
                },
                sphere: function() {
                    i.polygonStart();
                    i.lineStart();
                    r(null, null, 1, i);
                    i.lineEnd();
                    i.polygonEnd();
                }
            }, c, h, p, d, v = er(), m = n(v), g;
            return o;
        };
    }
    function Zn(e) {
        return e.length > 1;
    }
    function er() {
        var e = [], t;
        return {
            lineStart: function() {
                e.push(t = []);
            },
            point: function(e, n) {
                t.push([ e, n ]);
            },
            lineEnd: G,
            buffer: function() {
                var n = e;
                e = [];
                t = null;
                return n;
            },
            rejoin: function() {
                e.length > 1 && e.push(e.pop().concat(e.shift()));
            }
        };
    }
    function tr(e, t) {
        if (!(n = e.length)) return 0;
        var n, r = 0, i = 0, s = e[0], o = s[0], u = s[1], a = Math.cos(u), f = Math.atan2(t * Math.sin(o) * a, Math.sin(u)), l = 1 - t * Math.cos(o) * a, c = f, h, p;
        while (++r < n) {
            s = e[r];
            a = Math.cos(u = s[1]);
            h = Math.atan2(t * Math.sin(o = s[0]) * a, Math.sin(u));
            p = 1 - t * Math.cos(o) * a;
            if (Math.abs(l - 2) < vt && Math.abs(p - 2) < vt) continue;
            Math.abs(p) < vt || Math.abs(l) < vt || (Math.abs(Math.abs(h - f) - dt) < vt ? p + l > 2 && (i += 4 * (h - f)) : Math.abs(l - 2) < vt ? i += 4 * (h - c) : i += ((3 * dt + h - f) % (2 * dt) - dt) * (l + p));
            c = f, f = h, l = p;
        }
        return i;
    }
    function nr(e, t) {
        return ((e = e.point)[0] < 0 ? e[1] - dt / 2 - vt : dt / 2 - e[1]) - ((t = t.point)[0] < 0 ? t[1] - dt / 2 - vt : dt / 2 - t[1]);
    }
    function ir(e) {
        var t = NaN, n = NaN, r = NaN, i;
        return {
            lineStart: function() {
                e.lineStart();
                i = 1;
            },
            point: function(s, o) {
                var u = s > 0 ? dt : -dt, a = Math.abs(s - t);
                if (Math.abs(a - dt) < vt) {
                    e.point(t, n = (n + o) / 2 > 0 ? dt / 2 : -dt / 2);
                    e.point(r, n);
                    e.lineEnd();
                    e.lineStart();
                    e.point(u, n);
                    e.point(s, n);
                    i = 0;
                } else if (r !== u && a >= dt) {
                    Math.abs(t - r) < vt && (t -= r * vt);
                    Math.abs(s - u) < vt && (s -= u * vt);
                    n = sr(t, n, s, o);
                    e.point(r, n);
                    e.lineEnd();
                    e.lineStart();
                    e.point(u, n);
                    i = 0;
                }
                e.point(t = s, n = o);
                r = u;
            },
            lineEnd: function() {
                e.lineEnd();
                t = n = NaN;
            },
            clean: function() {
                return 2 - i;
            }
        };
    }
    function sr(e, t, n, r) {
        var i, s, o = Math.sin(e - n);
        return Math.abs(o) > vt ? Math.atan((Math.sin(t) * (s = Math.cos(r)) * Math.sin(n) - Math.sin(r) * (i = Math.cos(t)) * Math.sin(e)) / (i * s * o)) : (t + r) / 2;
    }
    function or(e, t, n, r) {
        var i;
        if (e == null) {
            i = n * dt / 2;
            r.point(-dt, i);
            r.point(0, i);
            r.point(dt, i);
            r.point(dt, 0);
            r.point(dt, -i);
            r.point(0, -i);
            r.point(-dt, -i);
            r.point(-dt, 0);
            r.point(-dt, i);
        } else if (Math.abs(e[0] - t[0]) > vt) {
            var s = (e[0] < t[0] ? 1 : -1) * dt;
            i = n * s / 2;
            r.point(-s, i);
            r.point(0, i);
            r.point(s, i);
        } else r.point(t[0], t[1]);
    }
    function ur(e) {
        function s(e, n) {
            return Math.cos(e) * Math.cos(n) > t;
        }
        function o(e) {
            var t, i, o, f, l;
            return {
                lineStart: function() {
                    f = o = !1;
                    l = 1;
                },
                point: function(c, h) {
                    var p = [ c, h ], d, v = s(c, h), m = n ? v ? 0 : a(c, h) : v ? a(c + (c < 0 ? dt : -dt), h) : 0;
                    !t && (f = o = v) && e.lineStart();
                    if (v !== o) {
                        d = u(t, p);
                        if (Kn(t, d) || Kn(p, d)) {
                            p[0] += vt;
                            p[1] += vt;
                            v = s(p[0], p[1]);
                        }
                    }
                    if (v !== o) {
                        l = 0;
                        if (v) {
                            e.lineStart();
                            d = u(p, t);
                            e.point(d[0], d[1]);
                        } else {
                            d = u(t, p);
                            e.point(d[0], d[1]);
                            e.lineEnd();
                        }
                        t = d;
                    } else if (r && t && n ^ v) {
                        var g;
                        if (!(m & i) && (g = u(p, t, !0))) {
                            l = 0;
                            if (n) {
                                e.lineStart();
                                e.point(g[0][0], g[0][1]);
                                e.point(g[1][0], g[1][1]);
                                e.lineEnd();
                            } else {
                                e.point(g[1][0], g[1][1]);
                                e.lineEnd();
                                e.lineStart();
                                e.point(g[0][0], g[0][1]);
                            }
                        }
                    }
                    v && (!t || !Kn(t, p)) && e.point(p[0], p[1]);
                    t = p, o = v, i = m;
                },
                lineEnd: function() {
                    o && e.lineEnd();
                    t = null;
                },
                clean: function() {
                    return l | (f && o) << 1;
                }
            };
        }
        function u(e, n, r) {
            var i = Rn(e), s = Rn(n), o = [ 1, 0, 0 ], u = zn(i, s), a = Un(u, u), f = u[0], l = a - f * f;
            if (!l) return !r && e;
            var c = t * a / l, h = -t * f / l, p = zn(o, u), d = Xn(o, c), v = Xn(u, h);
            Wn(d, v);
            var m = p, g = Un(d, m), y = Un(m, m), b = g * g - y * (Un(d, d) - 1);
            if (b < 0) return;
            var w = Math.sqrt(b), E = Xn(m, (-g - w) / y);
            Wn(E, d);
            E = Jn(E);
            if (!r) return E;
            var S = e[0], x = n[0], T = e[1], N = n[1], C;
            x < S && (C = S, S = x, x = C);
            var k = x - S, L = Math.abs(k - dt) < vt, A = L || k < vt;
            !L && N < T && (C = T, T = N, N = C);
            if (A ? L ? T + N > 0 ^ E[1] < (Math.abs(E[0] - S) < vt ? T : N) : T <= E[1] && E[1] <= N : k > dt ^ (S <= E[0] && E[0] <= x)) {
                var O = Xn(m, (-g + w) / y);
                Wn(O, d);
                return [ E, Jn(O) ];
            }
        }
        function a(t, r) {
            var i = n ? e : dt - e, s = 0;
            t < -i ? s |= 1 : t > i && (s |= 2);
            r < -i ? s |= 4 : r > i && (s |= 8);
            return s;
        }
        var t = Math.cos(e), n = t > 0, r = Math.abs(t) > vt, i = Er(e, 6 * mt);
        return Yn(s, o, i);
    }
    function fr(t, n, r, i) {
        function s(e, i) {
            return Math.abs(e[0] - t) < vt ? i > 0 ? 0 : 3 : Math.abs(e[0] - r) < vt ? i > 0 ? 2 : 1 : Math.abs(e[1] - n) < vt ? i > 0 ? 1 : 0 : i > 0 ? 3 : 2;
        }
        function o(e, t) {
            return u(e.point, t.point);
        }
        function u(e, t) {
            var n = s(e, 1), r = s(t, 1);
            return n !== r ? n - r : n === 0 ? t[1] - e[1] : n === 1 ? e[0] - t[0] : n === 2 ? e[1] - t[1] : t[0] - e[0];
        }
        function a(e, s) {
            var o = s[0] - e[0], u = s[1] - e[1], a = [ 0, 1 ];
            if (Math.abs(o) < vt && Math.abs(u) < vt) return t <= e[0] && e[0] <= r && n <= e[1] && e[1] <= i;
            if (lr(t - e[0], o, a) && lr(e[0] - r, -o, a) && lr(n - e[1], u, a) && lr(e[1] - i, -u, a)) {
                if (a[1] < 1) {
                    s[0] = e[0] + a[1] * o;
                    s[1] = e[1] + a[1] * u;
                }
                if (a[0] > 0) {
                    e[0] += a[0] * o;
                    e[1] += a[0] * u;
                }
                return !0;
            }
            return !1;
        }
        return function(f) {
            function m(e) {
                var o = s(e, -1), u = g([ o === 0 || o === 3 ? t : r, o > 1 ? i : n ]);
                return u;
            }
            function g(e) {
                var t = 0, n = p.length, r = e[1];
                for (var i = 0; i < n; ++i) for (var s = 1, o = p[i], u = o.length, a = o[0]; s < u; ++s) {
                    b = o[s];
                    a[1] <= r ? b[1] > r && y(a, b, e) > 0 && ++t : b[1] <= r && y(a, b, e) < 0 && --t;
                    a = b;
                }
                return t !== 0;
            }
            function y(e, t, n) {
                return (t[0] - e[0]) * (n[1] - e[1]) - (n[0] - e[0]) * (t[1] - e[1]);
            }
            function w(e, o, a, f) {
                var l = 0, c = 0;
                if (e == null || (l = s(e, a)) !== (c = s(o, a)) || u(e, o) < 0 ^ a > 0) {
                    do f.point(l === 0 || l === 3 ? t : r, l > 1 ? i : n); while ((l = (l + a + 4) % 4) !== c);
                } else f.point(o[0], o[1]);
            }
            function E(e, s) {
                return t <= e && e <= r && n <= s && s <= i;
            }
            function S(e, t) {
                E(e, t) && f.point(e, t);
            }
            function O() {
                v.point = _;
                p && p.push(d = []);
                A = !0;
                L = !1;
                C = k = NaN;
            }
            function M() {
                if (h) {
                    _(x, T);
                    N && L && c.rejoin();
                    h.push(c.buffer());
                }
                v.point = S;
                L && f.lineEnd();
            }
            function _(e, t) {
                e = Math.max(-ar, Math.min(ar, e));
                t = Math.max(-ar, Math.min(ar, t));
                var n = E(e, t);
                p && d.push([ e, t ]);
                if (A) {
                    x = e, T = t, N = n;
                    A = !1;
                    if (n) {
                        f.lineStart();
                        f.point(e, t);
                    }
                } else if (n && L) f.point(e, t); else {
                    var r = [ C, k ], i = [ e, t ];
                    if (a(r, i)) {
                        if (!L) {
                            f.lineStart();
                            f.point(r[0], r[1]);
                        }
                        f.point(i[0], i[1]);
                        n || f.lineEnd();
                    } else {
                        f.lineStart();
                        f.point(e, t);
                    }
                }
                C = e, k = t, L = n;
            }
            var l = f, c = er(), h, p, d, v = {
                point: S,
                lineStart: O,
                lineEnd: M,
                polygonStart: function() {
                    f = c;
                    h = [];
                    p = [];
                },
                polygonEnd: function() {
                    f = l;
                    if ((h = e.merge(h)).length) {
                        f.polygonStart();
                        Qn(h, o, m, w, f);
                        f.polygonEnd();
                    } else if (g([ t, n ])) {
                        f.polygonStart(), f.lineStart();
                        w(null, null, 1, f);
                        f.lineEnd(), f.polygonEnd();
                    }
                    h = p = d = null;
                }
            }, x, T, N, C, k, L, A;
            return v;
        };
    }
    function lr(e, t, n) {
        if (Math.abs(t) < vt) return e <= 0;
        var r = e / t;
        if (t > 0) {
            if (r > n[1]) return !1;
            r > n[0] && (n[0] = r);
        } else {
            if (r < n[0]) return !1;
            r < n[1] && (n[1] = r);
        }
        return !0;
    }
    function cr(e, t) {
        function n(n, r) {
            return n = e(n, r), t(n[0], n[1]);
        }
        e.invert && t.invert && (n.invert = function(n, r) {
            return n = t.invert(n, r), n && e.invert(n[0], n[1]);
        });
        return n;
    }
    function hr(e) {
        function r(t) {
            function c(n, r) {
                n = e(n, r);
                t.point(n[0], n[1]);
            }
            function h() {
                s = NaN;
                l.point = p;
                t.lineStart();
            }
            function p(l, c) {
                var h = Rn([ l, c ]), p = e(l, c);
                i(s, o, r, u, a, f, s = p[0], o = p[1], r = l, u = h[0], a = h[1], f = h[2], n, t);
                t.point(s, o);
            }
            function d() {
                l.point = c;
                t.lineEnd();
            }
            function v() {
                var e, c, v, m, g, y, b;
                h();
                l.point = function(t, n) {
                    p(e = t, c = n), v = s, m = o, g = u, y = a, b = f;
                    l.point = p;
                };
                l.lineEnd = function() {
                    i(s, o, r, u, a, f, v, m, e, g, y, b, n, t);
                    l.lineEnd = d;
                    d();
                };
            }
            var r, s, o, u, a, f, l = {
                point: c,
                lineStart: h,
                lineEnd: d,
                polygonStart: function() {
                    t.polygonStart();
                    l.lineStart = v;
                },
                polygonEnd: function() {
                    t.polygonEnd();
                    l.lineStart = h;
                }
            };
            return l;
        }
        function i(n, r, s, o, u, a, f, l, c, h, p, d, v, m) {
            var g = f - n, y = l - r, b = g * g + y * y;
            if (b > 4 * t && v--) {
                var w = o + h, E = u + p, S = a + d, x = Math.sqrt(w * w + E * E + S * S), T = Math.asin(S /= x), N = Math.abs(Math.abs(S) - 1) < vt ? (s + c) / 2 : Math.atan2(E, w), C = e(N, T), k = C[0], L = C[1], A = k - n, O = L - r, M = y * A - g * O;
                if (M * M / b > t || Math.abs((g * A + y * O) / b - .5) > .3) {
                    i(n, r, s, o, u, a, k, L, N, w /= x, E /= x, S, v, m);
                    m.point(k, L);
                    i(k, L, N, w, E, S, f, l, c, h, p, d, v, m);
                }
            }
        }
        var t = .5, n = 16;
        r.precision = function(e) {
            if (!arguments.length) return Math.sqrt(t);
            n = (t = e * e) > 0 && 16;
            return r;
        };
        return r;
    }
    function pr(e) {
        return dr(function() {
            return e;
        })();
    }
    function dr(t) {
        function w(e) {
            e = i(e[0] * mt, e[1] * mt);
            return [ e[0] * o + d, v - e[1] * o ];
        }
        function E(e) {
            e = i.invert((e[0] - d) / o, (v - e[1]) / o);
            return e && [ e[0] * gt, e[1] * gt ];
        }
        function S() {
            i = cr(r = gr(c, h, p), n);
            var e = n(f, l);
            d = u - e[0] * o;
            v = a + e[1] * o;
            return w;
        }
        var n, r, i, s = hr(function(e, t) {
            e = n(e, t);
            return [ e[0] * o + d, v - e[1] * o ];
        }), o = 150, u = 480, a = 250, f = 0, l = 0, c = 0, h = 0, p = 0, d, v, m = rr, g = Gt, y = null, b = null;
        w.stream = function(e) {
            return vr(r, m(s(g(e))));
        };
        w.clipAngle = function(e) {
            if (!arguments.length) return y;
            m = e == null ? (y = e, rr) : ur((y = +e) * mt);
            return w;
        };
        w.clipExtent = function(e) {
            if (!arguments.length) return b;
            b = e;
            g = e == null ? Gt : fr(e[0][0], e[0][1], e[1][0], e[1][1]);
            return w;
        };
        w.scale = function(e) {
            if (!arguments.length) return o;
            o = +e;
            return S();
        };
        w.translate = function(e) {
            if (!arguments.length) return [ u, a ];
            u = +e[0];
            a = +e[1];
            return S();
        };
        w.center = function(e) {
            if (!arguments.length) return [ f * gt, l * gt ];
            f = e[0] % 360 * mt;
            l = e[1] % 360 * mt;
            return S();
        };
        w.rotate = function(e) {
            if (!arguments.length) return [ c * gt, h * gt, p * gt ];
            c = e[0] % 360 * mt;
            h = e[1] % 360 * mt;
            p = e.length > 2 ? e[2] % 360 * mt : 0;
            return S();
        };
        e.rebind(w, s, "precision");
        return function() {
            n = t.apply(this, arguments);
            w.invert = n.invert && E;
            return S();
        };
    }
    function vr(e, t) {
        return {
            point: function(n, r) {
                r = e(n * mt, r * mt), n = r[0];
                t.point(n > dt ? n - 2 * dt : n < -dt ? n + 2 * dt : n, r[1]);
            },
            sphere: function() {
                t.sphere();
            },
            lineStart: function() {
                t.lineStart();
            },
            lineEnd: function() {
                t.lineEnd();
            },
            polygonStart: function() {
                t.polygonStart();
            },
            polygonEnd: function() {
                t.polygonEnd();
            }
        };
    }
    function mr(e, t) {
        return [ e, t ];
    }
    function gr(e, t, n) {
        return e ? t || n ? cr(br(e), wr(t, n)) : br(e) : t || n ? wr(t, n) : mr;
    }
    function yr(e) {
        return function(t, n) {
            return t += e, [ t > dt ? t - 2 * dt : t < -dt ? t + 2 * dt : t, n ];
        };
    }
    function br(e) {
        var t = yr(e);
        t.invert = yr(-e);
        return t;
    }
    function wr(e, t) {
        function o(e, t) {
            var o = Math.cos(t), u = Math.cos(e) * o, a = Math.sin(e) * o, f = Math.sin(t), l = f * n + u * r;
            return [ Math.atan2(a * i - l * s, u * n - f * r), Math.asin(Math.max(-1, Math.min(1, l * i + a * s))) ];
        }
        var n = Math.cos(e), r = Math.sin(e), i = Math.cos(t), s = Math.sin(t);
        o.invert = function(e, t) {
            var o = Math.cos(t), u = Math.cos(e) * o, a = Math.sin(e) * o, f = Math.sin(t), l = f * i - a * s;
            return [ Math.atan2(a * i + f * s, u * n + l * r), Math.asin(Math.max(-1, Math.min(1, l * n - u * r))) ];
        };
        return o;
    }
    function Er(e, t) {
        var n = Math.cos(e), r = Math.sin(e);
        return function(i, s, o, u) {
            if (i != null) {
                i = Sr(n, i);
                s = Sr(n, s);
                if (o > 0 ? i < s : i > s) i += o * 2 * dt;
            } else {
                i = e + o * 2 * dt;
                s = e;
            }
            var a;
            for (var f = o * t, l = i; o > 0 ? l > s : l < s; l -= f) u.point((a = Jn([ n, -r * Math.cos(l), -r * Math.sin(l) ]))[0], a[1]);
        };
    }
    function Sr(e, t) {
        var n = Rn(t);
        n[0] -= e;
        Vn(n);
        var r = bt(-n[1]);
        return ((-n[2] < 0 ? -r : r) + 2 * Math.PI - vt) % (2 * Math.PI);
    }
    function xr(t, n, r) {
        var i = e.range(t, n - vt, r).concat(n);
        return function(e) {
            return i.map(function(t) {
                return [ e, t ];
            });
        };
    }
    function Tr(t, n, r) {
        var i = e.range(t, n - vt, r).concat(n);
        return function(e) {
            return i.map(function(t) {
                return [ t, e ];
            });
        };
    }
    function Nr(e) {
        return e.source;
    }
    function Cr(e) {
        return e.target;
    }
    function kr(e, t, n, r) {
        var i = Math.cos(t), s = Math.sin(t), o = Math.cos(r), u = Math.sin(r), a = i * Math.cos(e), f = i * Math.sin(e), l = o * Math.cos(n), c = o * Math.sin(n), h = 2 * Math.asin(Math.sqrt(xt(r - t) + i * o * xt(n - e))), p = 1 / Math.sin(h), d = h ? function(e) {
            var t = Math.sin(e *= h) * p, n = Math.sin(h - e) * p, r = n * a + t * l, i = n * f + t * c, o = n * s + t * u;
            return [ Math.atan2(i, r) * gt, Math.atan2(o, Math.sqrt(r * r + i * i)) * gt ];
        } : function() {
            return [ e * gt, t * gt ];
        };
        d.distance = h;
        return d;
    }
    function Or() {
        function r(r, i) {
            var s = Math.sin(i *= mt), o = Math.cos(i), u = Math.abs((r *= mt) - e), a = Math.cos(u);
            Lr += Math.atan2(Math.sqrt((u = o * Math.sin(u)) * u + (u = n * s - t * o * a) * u), t * s + n * o * a);
            e = r, t = s, n = o;
        }
        var e, t, n;
        Ar.point = function(i, s) {
            e = i * mt, t = Math.sin(s *= mt), n = Math.cos(s);
            Ar.point = r;
        };
        Ar.lineEnd = function() {
            Ar.point = Ar.lineEnd = G;
        };
    }
    function Mr(e) {
        var t = 0, n = dt / 3, r = dr(e), i = r(t, n);
        i.parallels = function(e) {
            return arguments.length ? r(t = e[0] * dt / 180, n = e[1] * dt / 180) : [ t / dt * 180, n / dt * 180 ];
        };
        return i;
    }
    function _r(e, t) {
        function o(e, t) {
            var n = Math.sqrt(i - 2 * r * Math.sin(t)) / r;
            return [ n * Math.sin(e *= r), s - n * Math.cos(e) ];
        }
        var n = Math.sin(e), r = (n + Math.sin(t)) / 2, i = 1 + n * (2 * r - n), s = Math.sqrt(i) / r;
        o.invert = function(e, t) {
            var n = s - t;
            return [ Math.atan2(e, n) / r, Math.asin((i - (e * e + n * n) * r * r) / (2 * r)) ];
        };
        return o;
    }
    function Dr(e, t) {
        var n = e(t[0]), r = e([ .5 * (t[0][0] + t[1][0]), t[0][1] ]), i = e([ t[1][0], t[0][1] ]), s = e(t[1]), o = r[1] - n[1], u = r[0] - n[0], a = i[1] - r[1], f = i[0] - r[0], l = o / u, c = a / f, h = .5 * (l * c * (n[1] - i[1]) + c * (n[0] + r[0]) - l * (r[0] + i[0])) / (c - l), p = (.5 * (n[0] + r[0]) - h) / l + .5 * (n[1] + r[1]), d = s[0] - h, v = s[1] - p, m = n[0] - h, g = n[1] - p, y = d * d + v * v, b = m * m + g * g, w = Math.atan2(v, d), E = Math.atan2(g, m);
        return function(t) {
            var n = t[0] - h, r = t[1] - p, i = n * n + r * r, s = Math.atan2(r, n);
            if (y < i && i < b && w < s && s < E) return e.invert(t);
        };
    }
    function jr() {
        function i(e, t) {
            Hr += r * e - n * t;
            n = e, r = t;
        }
        var e, t, n, r;
        Br.point = function(s, o) {
            Br.point = i;
            e = n = s, t = r = o;
        };
        Br.lineEnd = function() {
            i(e, t);
        };
    }
    function Fr() {
        function r(n, r) {
            t.push("M", n, ",", r, e);
        }
        function i(e, r) {
            t.push("M", e, ",", r);
            n.point = s;
        }
        function s(e, n) {
            t.push("L", e, ",", n);
        }
        function o() {
            n.point = r;
        }
        function u() {
            t.push("Z");
        }
        var e = Xr(4.5), t = [], n = {
            point: r,
            lineStart: function() {
                n.point = i;
            },
            lineEnd: o,
            polygonStart: function() {
                n.lineEnd = u;
            },
            polygonEnd: function() {
                n.lineEnd = o;
                n.point = r;
            },
            pointRadius: function(t) {
                e = Xr(t);
                return n;
            },
            result: function() {
                if (t.length) {
                    var e = t.join("");
                    t = [];
                    return e;
                }
            }
        };
        return n;
    }
    function qr(e, t) {
        if (Mn) return;
        Dn += e;
        Pn += t;
        ++Hn;
    }
    function Rr() {
        function n(n, r) {
            var i = n - e, s = r - t, o = Math.sqrt(i * i + s * s);
            Dn += o * (e + n) / 2;
            Pn += o * (t + r) / 2;
            Hn += o;
            e = n, t = r;
        }
        var e, t;
        if (Mn !== 1) {
            if (!(Mn < 1)) return;
            Mn = 1;
            Dn = Pn = Hn = 0;
        }
        Ir.point = function(r, i) {
            Ir.point = n;
            e = r, t = i;
        };
    }
    function Ur() {
        Ir.point = qr;
    }
    function zr() {
        function i(e, t) {
            var i = r * e - n * t;
            Dn += i * (n + e);
            Pn += i * (r + t);
            Hn += i * 3;
            n = e, r = t;
        }
        var e, t, n, r;
        if (Mn < 2) {
            Mn = 2;
            Dn = Pn = Hn = 0;
        }
        Ir.point = function(s, o) {
            Ir.point = i;
            e = n = s, t = r = o;
        };
        Ir.lineEnd = function() {
            i(e, t);
        };
    }
    function Wr(e) {
        function r(n, r) {
            e.moveTo(n, r);
            e.arc(n, r, t, 0, 2 * dt);
        }
        function i(t, r) {
            e.moveTo(t, r);
            n.point = s;
        }
        function s(t, n) {
            e.lineTo(t, n);
        }
        function o() {
            n.point = r;
        }
        function u() {
            e.closePath();
        }
        var t = 4.5, n = {
            point: r,
            lineStart: function() {
                n.point = i;
            },
            lineEnd: o,
            polygonStart: function() {
                n.lineEnd = u;
            },
            polygonEnd: function() {
                n.lineEnd = o;
                n.point = r;
            },
            pointRadius: function(e) {
                t = e;
                return n;
            },
            result: G
        };
        return n;
    }
    function Xr(e) {
        return "m0," + e + "a" + e + "," + e + " 0 1,1 0," + -2 * e + "a" + e + "," + e + " 0 1,1 0," + 2 * e + "z";
    }
    function Vr(e) {
        var t = hr(function(t, n) {
            return e([ t * gt, n * gt ]);
        });
        return function(e) {
            e = t(e);
            return {
                point: function(t, n) {
                    e.point(t * mt, n * mt);
                },
                sphere: function() {
                    e.sphere();
                },
                lineStart: function() {
                    e.lineStart();
                },
                lineEnd: function() {
                    e.lineEnd();
                },
                polygonStart: function() {
                    e.polygonStart();
                },
                polygonEnd: function() {
                    e.polygonEnd();
                }
            };
        };
    }
    function $r(e, t) {
        function n(t, n) {
            var r = Math.cos(t), i = Math.cos(n), s = e(r * i);
            return [ s * i * Math.sin(t), s * Math.sin(n) ];
        }
        n.invert = function(e, n) {
            var r = Math.sqrt(e * e + n * n), i = t(r), s = Math.sin(i), o = Math.cos(i);
            return [ Math.atan2(e * s, r * o), Math.asin(r && n * s / r) ];
        };
        return n;
    }
    function Qr(e, t) {
        function o(e, t) {
            var n = Math.abs(Math.abs(t) - dt / 2) < vt ? 0 : s / Math.pow(r(t), i);
            return [ n * Math.sin(i * e), s - n * Math.cos(i * e) ];
        }
        var n = Math.cos(e), r = function(e) {
            return Math.tan(dt / 4 + e / 2);
        }, i = e === t ? Math.sin(e) : Math.log(n / Math.cos(t)) / Math.log(r(t) / r(e)), s = n * Math.pow(r(e), i) / i;
        if (!i) return Zr;
        o.invert = function(e, t) {
            var n = s - t, r = yt(i) * Math.sqrt(e * e + n * n);
            return [ Math.atan2(e, n) / i, 2 * Math.atan(Math.pow(s / r, 1 / i)) - dt / 2 ];
        };
        return o;
    }
    function Gr(e, t) {
        function s(e, t) {
            var n = i - t;
            return [ n * Math.sin(r * e), i - n * Math.cos(r * e) ];
        }
        var n = Math.cos(e), r = e === t ? Math.sin(e) : (n - Math.cos(t)) / (t - e), i = n / r + e;
        if (Math.abs(r) < vt) return mr;
        s.invert = function(e, t) {
            var n = i - t;
            return [ Math.atan2(e, n) / r, i - yt(r) * Math.sqrt(e * e + n * n) ];
        };
        return s;
    }
    function Zr(e, t) {
        return [ e, Math.log(Math.tan(dt / 4 + t / 2)) ];
    }
    function ei(e) {
        var t = pr(e), n = t.scale, r = t.translate, i = t.clipExtent, s;
        t.scale = function() {
            var e = n.apply(t, arguments);
            return e === t ? s ? t.clipExtent(null) : t : e;
        };
        t.translate = function() {
            var e = r.apply(t, arguments);
            return e === t ? s ? t.clipExtent(null) : t : e;
        };
        t.clipExtent = function(e) {
            var o = i.apply(t, arguments);
            if (o === t) {
                if (s = e == null) {
                    var u = dt * n(), a = r();
                    i([ [ a[0] - u, a[1] - u ], [ a[0] + u, a[1] + u ] ]);
                }
            } else s && (o = null);
            return o;
        };
        return t.clipExtent(null);
    }
    function ri(e, t) {
        var n = Math.cos(t) * Math.sin(e);
        return [ Math.log((1 + n) / (1 - n)) / 2, Math.atan2(Math.tan(t), Math.cos(e)) ];
    }
    function ii(e) {
        function u(s) {
            function d() {
                u.push("M", i(e(a), o));
            }
            var u = [], a = [], f = -1, l = s.length, c, h = Qt(t), p = Qt(n);
            while (++f < l) if (r.call(this, c = s[f], f)) a.push([ +h.call(this, c, f), +p.call(this, c, f) ]); else if (a.length) {
                d();
                a = [];
            }
            a.length && d();
            return u.length ? u.join("") : null;
        }
        var t = si, n = oi, r = $n, i = ai, s = i.key, o = .7;
        u.x = function(e) {
            if (!arguments.length) return t;
            t = e;
            return u;
        };
        u.y = function(e) {
            if (!arguments.length) return n;
            n = e;
            return u;
        };
        u.defined = function(e) {
            if (!arguments.length) return r;
            r = e;
            return u;
        };
        u.interpolate = function(e) {
            if (!arguments.length) return s;
            typeof e == "function" ? s = i = e : s = (i = ui.get(e) || ai).key;
            return u;
        };
        u.tension = function(e) {
            if (!arguments.length) return o;
            o = e;
            return u;
        };
        return u;
    }
    function si(e) {
        return e[0];
    }
    function oi(e) {
        return e[1];
    }
    function ai(e) {
        return e.join("L");
    }
    function fi(e) {
        return ai(e) + "Z";
    }
    function li(e) {
        var t = 0, n = e.length, r = e[0], i = [ r[0], ",", r[1] ];
        while (++t < n) i.push("V", (r = e[t])[1], "H", r[0]);
        return i.join("");
    }
    function ci(e) {
        var t = 0, n = e.length, r = e[0], i = [ r[0], ",", r[1] ];
        while (++t < n) i.push("H", (r = e[t])[0], "V", r[1]);
        return i.join("");
    }
    function hi(e, t) {
        return e.length < 4 ? ai(e) : e[1] + vi(e.slice(1, e.length - 1), mi(e, t));
    }
    function pi(e, t) {
        return e.length < 3 ? ai(e) : e[0] + vi((e.push(e[0]), e), mi([ e[e.length - 2] ].concat(e, [ e[1] ]), t));
    }
    function di(e, t) {
        return e.length < 3 ? ai(e) : e[0] + vi(e, mi(e, t));
    }
    function vi(e, t) {
        if (t.length < 1 || e.length != t.length && e.length != t.length + 2) return ai(e);
        var n = e.length != t.length, r = "", i = e[0], s = e[1], o = t[0], u = o, a = 1;
        if (n) {
            r += "Q" + (s[0] - o[0] * 2 / 3) + "," + (s[1] - o[1] * 2 / 3) + "," + s[0] + "," + s[1];
            i = e[1];
            a = 2;
        }
        if (t.length > 1) {
            u = t[1];
            s = e[a];
            a++;
            r += "C" + (i[0] + o[0]) + "," + (i[1] + o[1]) + "," + (s[0] - u[0]) + "," + (s[1] - u[1]) + "," + s[0] + "," + s[1];
            for (var f = 2; f < t.length; f++, a++) {
                s = e[a];
                u = t[f];
                r += "S" + (s[0] - u[0]) + "," + (s[1] - u[1]) + "," + s[0] + "," + s[1];
            }
        }
        if (n) {
            var l = e[a];
            r += "Q" + (s[0] + u[0] * 2 / 3) + "," + (s[1] + u[1] * 2 / 3) + "," + l[0] + "," + l[1];
        }
        return r;
    }
    function mi(e, t) {
        var n = [], r = (1 - t) / 2, i, s = e[0], o = e[1], u = 1, a = e.length;
        while (++u < a) {
            i = s;
            s = o;
            o = e[u];
            n.push([ r * (o[0] - i[0]), r * (o[1] - i[1]) ]);
        }
        return n;
    }
    function gi(e) {
        if (e.length < 3) return ai(e);
        var t = 1, n = e.length, r = e[0], i = r[0], s = r[1], o = [ i, i, i, (r = e[1])[0] ], u = [ s, s, s, r[1] ], a = [ i, ",", s ];
        Ni(a, o, u);
        while (++t < n) {
            r = e[t];
            o.shift();
            o.push(r[0]);
            u.shift();
            u.push(r[1]);
            Ni(a, o, u);
        }
        t = -1;
        while (++t < 2) {
            o.shift();
            o.push(r[0]);
            u.shift();
            u.push(r[1]);
            Ni(a, o, u);
        }
        return a.join("");
    }
    function yi(e) {
        if (e.length < 4) return ai(e);
        var t = [], n = -1, r = e.length, i, s = [ 0 ], o = [ 0 ];
        while (++n < 3) {
            i = e[n];
            s.push(i[0]);
            o.push(i[1]);
        }
        t.push(Ei(Ti, s) + "," + Ei(Ti, o));
        --n;
        while (++n < r) {
            i = e[n];
            s.shift();
            s.push(i[0]);
            o.shift();
            o.push(i[1]);
            Ni(t, s, o);
        }
        return t.join("");
    }
    function bi(e) {
        var t, n = -1, r = e.length, i = r + 4, s, o = [], u = [];
        while (++n < 4) {
            s = e[n % r];
            o.push(s[0]);
            u.push(s[1]);
        }
        t = [ Ei(Ti, o), ",", Ei(Ti, u) ];
        --n;
        while (++n < i) {
            s = e[n % r];
            o.shift();
            o.push(s[0]);
            u.shift();
            u.push(s[1]);
            Ni(t, o, u);
        }
        return t.join("");
    }
    function wi(e, t) {
        var n = e.length - 1;
        if (n) {
            var r = e[0][0], i = e[0][1], s = e[n][0] - r, o = e[n][1] - i, u = -1, a, f;
            while (++u <= n) {
                a = e[u];
                f = u / n;
                a[0] = t * a[0] + (1 - t) * (r + f * s);
                a[1] = t * a[1] + (1 - t) * (i + f * o);
            }
        }
        return gi(e);
    }
    function Ei(e, t) {
        return e[0] * t[0] + e[1] * t[1] + e[2] * t[2] + e[3] * t[3];
    }
    function Ni(e, t, n) {
        e.push("C", Ei(Si, t), ",", Ei(Si, n), ",", Ei(xi, t), ",", Ei(xi, n), ",", Ei(Ti, t), ",", Ei(Ti, n));
    }
    function Ci(e, t) {
        return (t[1] - e[1]) / (t[0] - e[0]);
    }
    function ki(e) {
        var t = 0, n = e.length - 1, r = [], i = e[0], s = e[1], o = r[0] = Ci(i, s);
        while (++t < n) r[t] = (o + (o = Ci(i = s, s = e[t + 1]))) / 2;
        r[t] = o;
        return r;
    }
    function Li(e) {
        var t = [], n, r, i, s, o = ki(e), u = -1, a = e.length - 1;
        while (++u < a) {
            n = Ci(e[u], e[u + 1]);
            if (Math.abs(n) < 1e-6) o[u] = o[u + 1] = 0; else {
                r = o[u] / n;
                i = o[u + 1] / n;
                s = r * r + i * i;
                if (s > 9) {
                    s = n * 3 / Math.sqrt(s);
                    o[u] = s * r;
                    o[u + 1] = s * i;
                }
            }
        }
        u = -1;
        while (++u <= a) {
            s = (e[Math.min(a, u + 1)][0] - e[Math.max(0, u - 1)][0]) / (6 * (1 + o[u] * o[u]));
            t.push([ s || 0, o[u] * s || 0 ]);
        }
        return t;
    }
    function Ai(e) {
        return e.length < 3 ? ai(e) : e[0] + vi(e, Li(e));
    }
    function Oi(e, t, n, r) {
        var i, s, o, u, a, f, l;
        i = r[e];
        s = i[0];
        o = i[1];
        i = r[t];
        u = i[0];
        a = i[1];
        i = r[n];
        f = i[0];
        l = i[1];
        return (l - o) * (u - s) - (a - o) * (f - s) > 0;
    }
    function Mi(e, t, n) {
        return (n[0] - t[0]) * (e[1] - t[1]) < (n[1] - t[1]) * (e[0] - t[0]);
    }
    function _i(e, t, n, r) {
        var i = e[0], s = n[0], o = t[0] - i, u = r[0] - s, a = e[1], f = n[1], l = t[1] - a, c = r[1] - f, h = (u * (a - f) - c * (i - s)) / (c * o - u * l);
        return [ i + h * o, a + h * l ];
    }
    function Pi(e, t) {
        var n = {
            list: e.map(function(e, t) {
                return {
                    index: t,
                    x: e[0],
                    y: e[1]
                };
            }).sort(function(e, t) {
                return e.y < t.y ? -1 : e.y > t.y ? 1 : e.x < t.x ? -1 : e.x > t.x ? 1 : 0;
            }),
            bottomSite: null
        }, r = {
            list: [],
            leftEnd: null,
            rightEnd: null,
            init: function() {
                r.leftEnd = r.createHalfEdge(null, "l");
                r.rightEnd = r.createHalfEdge(null, "l");
                r.leftEnd.r = r.rightEnd;
                r.rightEnd.l = r.leftEnd;
                r.list.unshift(r.leftEnd, r.rightEnd);
            },
            createHalfEdge: function(e, t) {
                return {
                    edge: e,
                    side: t,
                    vertex: null,
                    l: null,
                    r: null
                };
            },
            insert: function(e, t) {
                t.l = e;
                t.r = e.r;
                e.r.l = t;
                e.r = t;
            },
            leftBound: function(e) {
                var t = r.leftEnd;
                do t = t.r; while (t != r.rightEnd && i.rightOf(t, e));
                t = t.l;
                return t;
            },
            del: function(e) {
                e.l.r = e.r;
                e.r.l = e.l;
                e.edge = null;
            },
            right: function(e) {
                return e.r;
            },
            left: function(e) {
                return e.l;
            },
            leftRegion: function(e) {
                return e.edge == null ? n.bottomSite : e.edge.region[e.side];
            },
            rightRegion: function(e) {
                return e.edge == null ? n.bottomSite : e.edge.region[Di[e.side]];
            }
        }, i = {
            bisect: function(e, t) {
                var n = {
                    region: {
                        l: e,
                        r: t
                    },
                    ep: {
                        l: null,
                        r: null
                    }
                }, r = t.x - e.x, i = t.y - e.y, s = r > 0 ? r : -r, o = i > 0 ? i : -i;
                n.c = e.x * r + e.y * i + (r * r + i * i) * .5;
                if (s > o) {
                    n.a = 1;
                    n.b = i / r;
                    n.c /= r;
                } else {
                    n.b = 1;
                    n.a = r / i;
                    n.c /= i;
                }
                return n;
            },
            intersect: function(e, t) {
                var n = e.edge, r = t.edge;
                if (!n || !r || n.region.r == r.region.r) return null;
                var i = n.a * r.b - n.b * r.a;
                if (Math.abs(i) < 1e-10) return null;
                var s = (n.c * r.b - r.c * n.b) / i, o = (r.c * n.a - n.c * r.a) / i, u = n.region.r, a = r.region.r, f, l;
                if (u.y < a.y || u.y == a.y && u.x < a.x) {
                    f = e;
                    l = n;
                } else {
                    f = t;
                    l = r;
                }
                var c = s >= l.region.r.x;
                return c && f.side === "l" || !c && f.side === "r" ? null : {
                    x: s,
                    y: o
                };
            },
            rightOf: function(e, t) {
                var n = e.edge, r = n.region.r, i = t.x > r.x;
                if (i && e.side === "l") return 1;
                if (!i && e.side === "r") return 0;
                if (n.a === 1) {
                    var s = t.y - r.y, o = t.x - r.x, u = 0, a = 0;
                    if (!i && n.b < 0 || i && n.b >= 0) a = u = s >= n.b * o; else {
                        a = t.x + t.y * n.b > n.c;
                        n.b < 0 && (a = !a);
                        a || (u = 1);
                    }
                    if (!u) {
                        var f = r.x - n.region.l.x;
                        a = n.b * (o * o - s * s) < f * s * (1 + 2 * o / f + n.b * n.b);
                        n.b < 0 && (a = !a);
                    }
                } else {
                    var l = n.c - n.a * t.x, c = t.y - l, h = t.x - r.x, p = l - r.y;
                    a = c * c > h * h + p * p;
                }
                return e.side === "l" ? a : !a;
            },
            endPoint: function(e, n, r) {
                e.ep[n] = r;
                if (!e.ep[Di[n]]) return;
                t(e);
            },
            distance: function(e, t) {
                var n = e.x - t.x, r = e.y - t.y;
                return Math.sqrt(n * n + r * r);
            }
        }, s = {
            list: [],
            insert: function(e, t, n) {
                e.vertex = t;
                e.ystar = t.y + n;
                for (var r = 0, i = s.list, o = i.length; r < o; r++) {
                    var u = i[r];
                    if (e.ystar > u.ystar || e.ystar == u.ystar && t.x > u.vertex.x) continue;
                    break;
                }
                i.splice(r, 0, e);
            },
            del: function(e) {
                for (var t = 0, n = s.list, r = n.length; t < r && n[t] != e; ++t) ;
                n.splice(t, 1);
            },
            empty: function() {
                return s.list.length === 0;
            },
            nextEvent: function(e) {
                for (var t = 0, n = s.list, r = n.length; t < r; ++t) if (n[t] == e) return n[t + 1];
                return null;
            },
            min: function() {
                var e = s.list[0];
                return {
                    x: e.vertex.x,
                    y: e.ystar
                };
            },
            extractMin: function() {
                return s.list.shift();
            }
        };
        r.init();
        n.bottomSite = n.list.shift();
        var o = n.list.shift(), u, a, f, l, c, h, p, d, v, m, g, y, b;
        for (;;) {
            s.empty() || (u = s.min());
            if (o && (s.empty() || o.y < u.y || o.y == u.y && o.x < u.x)) {
                a = r.leftBound(o);
                f = r.right(a);
                p = r.rightRegion(a);
                y = i.bisect(p, o);
                h = r.createHalfEdge(y, "l");
                r.insert(a, h);
                m = i.intersect(a, h);
                if (m) {
                    s.del(a);
                    s.insert(a, m, i.distance(m, o));
                }
                a = h;
                h = r.createHalfEdge(y, "r");
                r.insert(a, h);
                m = i.intersect(h, f);
                m && s.insert(h, m, i.distance(m, o));
                o = n.list.shift();
            } else {
                if (!!s.empty()) break;
                a = s.extractMin();
                l = r.left(a);
                f = r.right(a);
                c = r.right(f);
                p = r.leftRegion(a);
                d = r.rightRegion(f);
                g = a.vertex;
                i.endPoint(a.edge, a.side, g);
                i.endPoint(f.edge, f.side, g);
                r.del(a);
                s.del(f);
                r.del(f);
                b = "l";
                if (p.y > d.y) {
                    v = p;
                    p = d;
                    d = v;
                    b = "r";
                }
                y = i.bisect(p, d);
                h = r.createHalfEdge(y, b);
                r.insert(l, h);
                i.endPoint(y, Di[b], g);
                m = i.intersect(l, h);
                if (m) {
                    s.del(l);
                    s.insert(l, m, i.distance(m, p));
                }
                m = i.intersect(h, c);
                m && s.insert(h, m, i.distance(m, p));
            }
        }
        for (a = r.right(r.leftEnd); a != r.rightEnd; a = r.right(a)) t(a.edge);
    }
    function Hi(e) {
        return e.x;
    }
    function Bi(e) {
        return e.y;
    }
    function ji() {
        return {
            leaf: !0,
            nodes: [],
            point: null,
            x: null,
            y: null
        };
    }
    function Fi(e, t, n, r, i, s) {
        if (!e(t, n, r, i, s)) {
            var o = (n + i) * .5, u = (r + s) * .5, a = t.nodes;
            a[0] && Fi(e, a[0], n, r, o, u);
            a[1] && Fi(e, a[1], o, r, i, u);
            a[2] && Fi(e, a[2], n, u, o, s);
            a[3] && Fi(e, a[3], o, u, i, s);
        }
    }
    function Ii(t, n) {
        t = e.rgb(t);
        n = e.rgb(n);
        var r = t.r, i = t.g, s = t.b, o = n.r - r, u = n.g - i, a = n.b - s;
        return function(e) {
            return "#" + zt(Math.round(r + o * e)) + zt(Math.round(i + u * e)) + zt(Math.round(s + a * e));
        };
    }
    function qi(e) {
        var t = [ e.a, e.b ], n = [ e.c, e.d ], r = Ui(t), i = Ri(t, n), s = Ui(zi(n, t, -i)) || 0;
        if (t[0] * n[1] < n[0] * t[1]) {
            t[0] *= -1;
            t[1] *= -1;
            r *= -1;
            i *= -1;
        }
        this.rotate = (r ? Math.atan2(t[1], t[0]) : Math.atan2(-n[0], n[1])) * gt;
        this.translate = [ e.e, e.f ];
        this.scale = [ r, s ];
        this.skew = s ? Math.atan2(i, s) * gt : 0;
    }
    function Ri(e, t) {
        return e[0] * t[0] + e[1] * t[1];
    }
    function Ui(e) {
        var t = Math.sqrt(Ri(e, e));
        if (t) {
            e[0] /= t;
            e[1] /= t;
        }
        return t;
    }
    function zi(e, t, n) {
        e[0] += n * t[0];
        e[1] += n * t[1];
        return e;
    }
    function Xi(e, t) {
        t -= e = +e;
        return function(n) {
            return e + t * n;
        };
    }
    function Vi(t, n) {
        var r = [], i = [], s, o = e.transform(t), u = e.transform(n), a = o.translate, f = u.translate, l = o.rotate, c = u.rotate, h = o.skew, p = u.skew, d = o.scale, v = u.scale;
        if (a[0] != f[0] || a[1] != f[1]) {
            r.push("translate(", null, ",", null, ")");
            i.push({
                i: 1,
                x: Xi(a[0], f[0])
            }, {
                i: 3,
                x: Xi(a[1], f[1])
            });
        } else f[0] || f[1] ? r.push("translate(" + f + ")") : r.push("");
        if (l != c) {
            l - c > 180 ? c += 360 : c - l > 180 && (l += 360);
            i.push({
                i: r.push(r.pop() + "rotate(", null, ")") - 2,
                x: Xi(l, c)
            });
        } else c && r.push(r.pop() + "rotate(" + c + ")");
        h != p ? i.push({
            i: r.push(r.pop() + "skewX(", null, ")") - 2,
            x: Xi(h, p)
        }) : p && r.push(r.pop() + "skewX(" + p + ")");
        if (d[0] != v[0] || d[1] != v[1]) {
            s = r.push(r.pop() + "scale(", null, ",", null, ")");
            i.push({
                i: s - 4,
                x: Xi(d[0], v[0])
            }, {
                i: s - 2,
                x: Xi(d[1], v[1])
            });
        } else (v[0] != 1 || v[1] != 1) && r.push(r.pop() + "scale(" + v + ")");
        s = i.length;
        return function(e) {
            var t = -1, n;
            while (++t < s) r[(n = i[t]).i] = n.x(e);
            return r.join("");
        };
    }
    function $i(e, t) {
        var n = {}, r = {}, i;
        for (i in e) i in t ? n[i] = Gi(i)(e[i], t[i]) : r[i] = e[i];
        for (i in t) i in e || (r[i] = t[i]);
        return function(e) {
            for (i in n) r[i] = n[i](e);
            return r;
        };
    }
    function Ji(e, t) {
        var n, r, i, s = 0, o = 0, u = [], a = [], f, l;
        e += "", t += "";
        Ki.lastIndex = 0;
        for (r = 0; n = Ki.exec(t); ++r) {
            n.index && u.push(t.substring(s, o = n.index));
            a.push({
                i: u.length,
                x: n[0]
            });
            u.push(null);
            s = Ki.lastIndex;
        }
        s < t.length && u.push(t.substring(s));
        for (r = 0, f = a.length; (n = Ki.exec(e)) && r < f; ++r) {
            l = a[r];
            if (l.x == n[0]) {
                if (l.i) if (u[l.i + 1] == null) {
                    u[l.i - 1] += l.x;
                    u.splice(l.i, 1);
                    for (i = r + 1; i < f; ++i) a[i].i--;
                } else {
                    u[l.i - 1] += l.x + u[l.i + 1];
                    u.splice(l.i, 2);
                    for (i = r + 1; i < f; ++i) a[i].i -= 2;
                } else if (u[l.i + 1] == null) u[l.i] = l.x; else {
                    u[l.i] = l.x + u[l.i + 1];
                    u.splice(l.i + 1, 1);
                    for (i = r + 1; i < f; ++i) a[i].i--;
                }
                a.splice(r, 1);
                f--;
                r--;
            } else l.x = Xi(parseFloat(n[0]), parseFloat(l.x));
        }
        while (r < f) {
            l = a.pop();
            if (u[l.i + 1] == null) u[l.i] = l.x; else {
                u[l.i] = l.x + u[l.i + 1];
                u.splice(l.i + 1, 1);
            }
            f--;
        }
        return u.length === 1 ? u[0] == null ? a[0].x : function() {
            return t;
        } : function(e) {
            for (r = 0; r < f; ++r) u[(l = a[r]).i] = l.x(e);
            return u.join("");
        };
    }
    function Qi(t, n) {
        var r = e.interpolators.length, i;
        while (--r >= 0 && !(i = e.interpolators[r](t, n))) ;
        return i;
    }
    function Gi(e) {
        return e == "transform" ? Vi : Qi;
    }
    function Yi(e, t) {
        var n = [], r = [], i = e.length, s = t.length, o = Math.min(e.length, t.length), u;
        for (u = 0; u < o; ++u) n.push(Qi(e[u], t[u]));
        for (; u < i; ++u) r[u] = e[u];
        for (; u < s; ++u) r[u] = t[u];
        return function(e) {
            for (u = 0; u < o; ++u) r[u] = n[u](e);
            return r;
        };
    }
    function ns(e) {
        return function(t) {
            return t <= 0 ? 0 : t >= 1 ? 1 : e(t);
        };
    }
    function rs(e) {
        return function(t) {
            return 1 - e(1 - t);
        };
    }
    function is(e) {
        return function(t) {
            return .5 * (t < .5 ? e(2 * t) : 2 - e(2 - 2 * t));
        };
    }
    function ss(e) {
        return e * e;
    }
    function os(e) {
        return e * e * e;
    }
    function us(e) {
        if (e <= 0) return 0;
        if (e >= 1) return 1;
        var t = e * e, n = t * e;
        return 4 * (e < .5 ? n : 3 * (e - t) + n - .75);
    }
    function as(e) {
        return function(t) {
            return Math.pow(t, e);
        };
    }
    function fs(e) {
        return 1 - Math.cos(e * dt / 2);
    }
    function ls(e) {
        return Math.pow(2, 10 * (e - 1));
    }
    function cs(e) {
        return 1 - Math.sqrt(1 - e * e);
    }
    function hs(e, t) {
        var n;
        arguments.length < 2 && (t = .45);
        arguments.length ? n = t / (2 * dt) * Math.asin(1 / e) : (e = 1, n = t / 4);
        return function(r) {
            return 1 + e * Math.pow(2, 10 * -r) * Math.sin((r - n) * 2 * dt / t);
        };
    }
    function ps(e) {
        e || (e = 1.70158);
        return function(t) {
            return t * t * ((e + 1) * t - e);
        };
    }
    function ds(e) {
        return e < 1 / 2.75 ? 7.5625 * e * e : e < 2 / 2.75 ? 7.5625 * (e -= 1.5 / 2.75) * e + .75 : e < 2.5 / 2.75 ? 7.5625 * (e -= 2.25 / 2.75) * e + .9375 : 7.5625 * (e -= 2.625 / 2.75) * e + .984375;
    }
    function vs(t, n) {
        t = e.hcl(t);
        n = e.hcl(n);
        var r = t.h, i = t.c, s = t.l, o = n.h - r, u = n.c - i, a = n.l - s;
        o > 180 ? o -= 360 : o < -180 && (o += 360);
        return function(e) {
            return kt(r + o * e, i + u * e, s + a * e) + "";
        };
    }
    function ms(t, n) {
        t = e.hsl(t);
        n = e.hsl(n);
        var r = t.h, i = t.s, s = t.l, o = n.h - r, u = n.s - i, a = n.l - s;
        o > 180 ? o -= 360 : o < -180 && (o += 360);
        return function(e) {
            return pt(r + o * e, i + u * e, s + a * e) + "";
        };
    }
    function gs(t, n) {
        t = e.lab(t);
        n = e.lab(n);
        var r = t.l, i = t.a, s = t.b, o = n.l - r, u = n.a - i, a = n.b - s;
        return function(e) {
            return Ht(r + o * e, i + u * e, s + a * e) + "";
        };
    }
    function ys(e, t) {
        t -= e;
        return function(n) {
            return Math.round(e + t * n);
        };
    }
    function bs(e, t) {
        t = t - (e = +e) ? 1 / (t - e) : 0;
        return function(n) {
            return (n - e) * t;
        };
    }
    function ws(e, t) {
        t = t - (e = +e) ? 1 / (t - e) : 0;
        return function(n) {
            return Math.max(0, Math.min(1, (n - e) * t));
        };
    }
    function Es(e) {
        var t = e.source, n = e.target, r = xs(t, n), i = [ t ];
        while (t !== r) {
            t = t.parent;
            i.push(t);
        }
        var s = i.length;
        while (n !== r) {
            i.splice(s, 0, n);
            n = n.parent;
        }
        return i;
    }
    function Ss(e) {
        var t = [], n = e.parent;
        while (n != null) {
            t.push(e);
            e = n;
            n = n.parent;
        }
        t.push(e);
        return t;
    }
    function xs(e, t) {
        if (e === t) return e;
        var n = Ss(e), r = Ss(t), i = n.pop(), s = r.pop(), o = null;
        while (i === s) {
            o = i;
            i = n.pop();
            s = r.pop();
        }
        return o;
    }
    function Ts(e) {
        e.fixed |= 2;
    }
    function Ns(e) {
        e.fixed &= -7;
    }
    function Cs(e) {
        e.fixed |= 4;
        e.px = e.x, e.py = e.y;
    }
    function ks(e) {
        e.fixed &= -5;
    }
    function Ls(e, t, n) {
        var r = 0, i = 0;
        e.charge = 0;
        if (!e.leaf) {
            var s = e.nodes, o = s.length, u = -1, a;
            while (++u < o) {
                a = s[u];
                if (a == null) continue;
                Ls(a, t, n);
                e.charge += a.charge;
                r += a.charge * a.cx;
                i += a.charge * a.cy;
            }
        }
        if (e.point) {
            if (!e.leaf) {
                e.point.x += Math.random() - .5;
                e.point.y += Math.random() - .5;
            }
            var f = t * n[e.point.index];
            e.charge += e.pointCharge = f;
            r += f * e.point.x;
            i += f * e.point.y;
        }
        e.cx = r / e.charge;
        e.cy = i / e.charge;
    }
    function Ms(t, n) {
        e.rebind(t, n, "sort", "children", "value");
        t.nodes = t;
        t.links = Hs;
        return t;
    }
    function _s(e) {
        return e.children;
    }
    function Ds(e) {
        return e.value;
    }
    function Ps(e, t) {
        return t.value - e.value;
    }
    function Hs(t) {
        return e.merge(t.map(function(e) {
            return (e.children || []).map(function(t) {
                return {
                    source: e,
                    target: t
                };
            });
        }));
    }
    function js(e) {
        return e.x;
    }
    function Fs(e) {
        return e.y;
    }
    function Is(e, t, n) {
        e.y0 = t;
        e.y = n;
    }
    function Us(t) {
        return e.range(t.length);
    }
    function zs(e) {
        var t = -1, n = e[0].length, r = [];
        while (++t < n) r[t] = 0;
        return r;
    }
    function Ws(e) {
        var t = 1, n = 0, r = e[0][1], i, s = e.length;
        for (; t < s; ++t) if ((i = e[t][1]) > r) {
            n = t;
            r = i;
        }
        return n;
    }
    function Xs(e) {
        return e.reduce(Vs, 0);
    }
    function Vs(e, t) {
        return e + t[1];
    }
    function $s(e, t) {
        return Js(e, Math.ceil(Math.log(t.length) / Math.LN2 + 1));
    }
    function Js(e, t) {
        var n = -1, r = +e[0], i = (e[1] - r) / t, s = [];
        while (++n <= t) s[n] = i * n + r;
        return s;
    }
    function Ks(t) {
        return [ e.min(t), e.max(t) ];
    }
    function Qs(e, t) {
        return e.parent == t.parent ? 1 : 2;
    }
    function Gs(e) {
        var t = e.children;
        return t && t.length ? t[0] : e._tree.thread;
    }
    function Ys(e) {
        var t = e.children, n;
        return t && (n = t.length) ? t[n - 1] : e._tree.thread;
    }
    function Zs(e, t) {
        var n = e.children;
        if (n && (i = n.length)) {
            var r, i, s = -1;
            while (++s < i) t(r = Zs(n[s], t), e) > 0 && (e = r);
        }
        return e;
    }
    function eo(e, t) {
        return e.x - t.x;
    }
    function to(e, t) {
        return t.x - e.x;
    }
    function no(e, t) {
        return e.depth - t.depth;
    }
    function ro(e, t) {
        function n(e, r) {
            var i = e.children;
            if (i && (a = i.length)) {
                var s, o = null, u = -1, a;
                while (++u < a) {
                    s = i[u];
                    n(s, o);
                    o = s;
                }
            }
            t(e, r);
        }
        n(e, null);
    }
    function io(e) {
        var t = 0, n = 0, r = e.children, i = r.length, s;
        while (--i >= 0) {
            s = r[i]._tree;
            s.prelim += t;
            s.mod += t;
            t += s.shift + (n += s.change);
        }
    }
    function so(e, t, n) {
        e = e._tree;
        t = t._tree;
        var r = n / (t.number - e.number);
        e.change += r;
        t.change -= r;
        t.shift += n;
        t.prelim += n;
        t.mod += n;
    }
    function oo(e, t, n) {
        return e._tree.ancestor.parent == t.parent ? e._tree.ancestor : n;
    }
    function uo(e, t) {
        return e.value - t.value;
    }
    function ao(e, t) {
        var n = e._pack_next;
        e._pack_next = t;
        t._pack_prev = e;
        t._pack_next = n;
        n._pack_prev = t;
    }
    function fo(e, t) {
        e._pack_next = t;
        t._pack_prev = e;
    }
    function lo(e, t) {
        var n = t.x - e.x, r = t.y - e.y, i = e.r + t.r;
        return i * i - n * n - r * r > .001;
    }
    function co(e) {
        function p(e) {
            n = Math.min(e.x - e.r, n);
            r = Math.max(e.x + e.r, r);
            i = Math.min(e.y - e.r, i);
            s = Math.max(e.y + e.r, s);
        }
        if (!(t = e.children) || !(h = t.length)) return;
        var t, n = Infinity, r = -Infinity, i = Infinity, s = -Infinity, o, u, a, f, l, c, h;
        t.forEach(ho);
        o = t[0];
        o.x = -o.r;
        o.y = 0;
        p(o);
        if (h > 1) {
            u = t[1];
            u.x = u.r;
            u.y = 0;
            p(u);
            if (h > 2) {
                a = t[2];
                mo(o, u, a);
                p(a);
                ao(o, a);
                o._pack_prev = a;
                ao(a, u);
                u = o._pack_next;
                for (f = 3; f < h; f++) {
                    mo(o, u, a = t[f]);
                    var d = 0, v = 1, m = 1;
                    for (l = u._pack_next; l !== u; l = l._pack_next, v++) if (lo(l, a)) {
                        d = 1;
                        break;
                    }
                    if (d == 1) for (c = o._pack_prev; c !== l._pack_prev; c = c._pack_prev, m++) if (lo(c, a)) break;
                    if (d) {
                        v < m || v == m && u.r < o.r ? fo(o, u = l) : fo(o = c, u);
                        f--;
                    } else {
                        ao(o, a);
                        u = a;
                        p(a);
                    }
                }
            }
        }
        var g = (n + r) / 2, y = (i + s) / 2, b = 0;
        for (f = 0; f < h; f++) {
            a = t[f];
            a.x -= g;
            a.y -= y;
            b = Math.max(b, a.r + Math.sqrt(a.x * a.x + a.y * a.y));
        }
        e.r = b;
        t.forEach(po);
    }
    function ho(e) {
        e._pack_next = e._pack_prev = e;
    }
    function po(e) {
        delete e._pack_next;
        delete e._pack_prev;
    }
    function vo(e, t, n, r) {
        var i = e.children;
        e.x = t += r * e.x;
        e.y = n += r * e.y;
        e.r *= r;
        if (i) {
            var s = -1, o = i.length;
            while (++s < o) vo(i[s], t, n, r);
        }
    }
    function mo(e, t, n) {
        var r = e.r + n.r, i = t.x - e.x, s = t.y - e.y;
        if (r && (i || s)) {
            var o = t.r + n.r, u = i * i + s * s;
            o *= o;
            r *= r;
            var a = .5 + (r - o) / (2 * u), f = Math.sqrt(Math.max(0, 2 * o * (r + u) - (r -= u) * r - o * o)) / (2 * u);
            n.x = e.x + a * i + f * s;
            n.y = e.y + a * s - f * i;
        } else {
            n.x = e.x + r;
            n.y = e.y;
        }
    }
    function go(t) {
        return 1 + e.max(t, function(e) {
            return e.y;
        });
    }
    function yo(e) {
        return e.reduce(function(e, t) {
            return e + t.x;
        }, 0) / e.length;
    }
    function bo(e) {
        var t = e.children;
        return t && t.length ? bo(t[0]) : e;
    }
    function wo(e) {
        var t = e.children, n;
        return t && (n = t.length) ? wo(t[n - 1]) : e;
    }
    function Eo(e) {
        return {
            x: e.x,
            y: e.y,
            dx: e.dx,
            dy: e.dy
        };
    }
    function So(e, t) {
        var n = e.x + t[3], r = e.y + t[0], i = e.dx - t[1] - t[3], s = e.dy - t[0] - t[2];
        if (i < 0) {
            n += i / 2;
            i = 0;
        }
        if (s < 0) {
            r += s / 2;
            s = 0;
        }
        return {
            x: n,
            y: r,
            dx: i,
            dy: s
        };
    }
    function xo(e) {
        var t = e[0], n = e[e.length - 1];
        return t < n ? [ t, n ] : [ n, t ];
    }
    function To(e) {
        return e.rangeExtent ? e.rangeExtent() : xo(e.range());
    }
    function No(e, t, n, r) {
        var i = n(e[0], e[1]), s = r(t[0], t[1]);
        return function(e) {
            return s(i(e));
        };
    }
    function Co(e, t) {
        var n = 0, r = e.length - 1, i = e[n], s = e[r], o;
        if (s < i) {
            o = n, n = r, r = o;
            o = i, i = s, s = o;
        }
        if (t = t(s - i)) {
            e[n] = t.floor(i);
            e[r] = t.ceil(s);
        }
        return e;
    }
    function ko(t, n, r, i) {
        var s = [], o = [], u = 0, a = Math.min(t.length, n.length) - 1;
        if (t[a] < t[0]) {
            t = t.slice().reverse();
            n = n.slice().reverse();
        }
        while (++u <= a) {
            s.push(r(t[u - 1], t[u]));
            o.push(i(n[u - 1], n[u]));
        }
        return function(n) {
            var r = e.bisect(t, n, 1, a) - 1;
            return o[r](s[r](n));
        };
    }
    function Lo(e, t, n, r) {
        function o() {
            var o = Math.min(e.length, t.length) > 2 ? ko : No, a = r ? ws : bs;
            i = o(e, t, a, n);
            s = o(t, e, a, Qi);
            return u;
        }
        function u(e) {
            return i(e);
        }
        var i, s;
        u.invert = function(e) {
            return s(e);
        };
        u.domain = function(t) {
            if (!arguments.length) return e;
            e = t.map(Number);
            return o();
        };
        u.range = function(e) {
            if (!arguments.length) return t;
            t = e;
            return o();
        };
        u.rangeRound = function(e) {
            return u.range(e).interpolate(ys);
        };
        u.clamp = function(e) {
            if (!arguments.length) return r;
            r = e;
            return o();
        };
        u.interpolate = function(e) {
            if (!arguments.length) return n;
            n = e;
            return o();
        };
        u.ticks = function(t) {
            return _o(e, t);
        };
        u.tickFormat = function(t, n) {
            return Do(e, t, n);
        };
        u.nice = function() {
            Co(e, Oo);
            return o();
        };
        u.copy = function() {
            return Lo(e, t, n, r);
        };
        return o();
    }
    function Ao(t, n) {
        return e.rebind(t, n, "range", "rangeRound", "interpolate", "clamp");
    }
    function Oo(e) {
        e = Math.pow(10, Math.round(Math.log(e) / Math.LN10) - 1);
        return e && {
            floor: function(t) {
                return Math.floor(t / e) * e;
            },
            ceil: function(t) {
                return Math.ceil(t / e) * e;
            }
        };
    }
    function Mo(e, t) {
        var n = xo(e), r = n[1] - n[0], i = Math.pow(10, Math.floor(Math.log(r / t) / Math.LN10)), s = t / r * i;
        s <= .15 ? i *= 10 : s <= .35 ? i *= 5 : s <= .75 && (i *= 2);
        n[0] = Math.ceil(n[0] / i) * i;
        n[1] = Math.floor(n[1] / i) * i + i * .5;
        n[2] = i;
        return n;
    }
    function _o(t, n) {
        return e.range.apply(e, Mo(t, n));
    }
    function Do(t, n, r) {
        var i = -Math.floor(Math.log(Mo(t, n)[2]) / Math.LN10 + .01);
        return e.format(r ? r.replace(dn, function(e, t, n, r, s, o, u, a, f, l) {
            return [ t, n, r, s, o, u, a, f || "." + (i - (l === "%") * 2), l ].join("");
        }) : ",." + i + "f");
    }
    function Po(e, t, n, r) {
        function i(t) {
            return e(n(t));
        }
        i.invert = function(t) {
            return r(e.invert(t));
        };
        i.domain = function(t) {
            if (!arguments.length) return e.domain().map(r);
            t[0] < 0 ? (n = Fo, r = Io) : (n = Bo, r = jo);
            e.domain(t.map(n));
            return i;
        };
        i.base = function(e) {
            if (!arguments.length) return t;
            t = +e;
            return i;
        };
        i.nice = function() {
            e.domain(Co(e.domain(), qo(t)));
            return i;
        };
        i.ticks = function() {
            var i = xo(e.domain()), s = [];
            if (i.every(isFinite)) {
                var o = Math.log(t), u = Math.floor(i[0] / o), a = Math.ceil(i[1] / o), f = r(i[0]), l = r(i[1]), c = t % 1 ? 2 : t;
                if (n === Fo) {
                    s.push(-Math.pow(t, -u));
                    for (; u++ < a; ) for (var h = c - 1; h > 0; h--) s.push(-Math.pow(t, -u) * h);
                } else {
                    for (; u < a; u++) for (var h = 1; h < c; h++) s.push(Math.pow(t, u) * h);
                    s.push(Math.pow(t, u));
                }
                for (u = 0; s[u] < f; u++) ;
                for (a = s.length; s[a - 1] > l; a--) ;
                s = s.slice(u, a);
            }
            return s;
        };
        i.tickFormat = function(e, s) {
            arguments.length < 2 && (s = Ho);
            if (!arguments.length) return s;
            var o = Math.log(t), u = Math.max(.1, e / i.ticks().length), a = n === Fo ? (f = -1e-12, Math.floor) : (f = 1e-12, Math.ceil), f;
            return function(e) {
                return e / r(o * a(n(e) / o + f)) <= u ? s(e) : "";
            };
        };
        i.copy = function() {
            return Po(e.copy(), t, n, r);
        };
        return Ao(i, e);
    }
    function Bo(e) {
        return Math.log(e < 0 ? 0 : e);
    }
    function jo(e) {
        return Math.exp(e);
    }
    function Fo(e) {
        return -Math.log(e > 0 ? 0 : -e);
    }
    function Io(e) {
        return -Math.exp(-e);
    }
    function qo(e) {
        e = Math.log(e);
        var t = {
            floor: function(t) {
                return Math.floor(t / e) * e;
            },
            ceil: function(t) {
                return Math.ceil(t / e) * e;
            }
        };
        return function() {
            return t;
        };
    }
    function Ro(e, t) {
        function i(t) {
            return e(n(t));
        }
        var n = Uo(t), r = Uo(1 / t);
        i.invert = function(t) {
            return r(e.invert(t));
        };
        i.domain = function(t) {
            if (!arguments.length) return e.domain().map(r);
            e.domain(t.map(n));
            return i;
        };
        i.ticks = function(e) {
            return _o(i.domain(), e);
        };
        i.tickFormat = function(e, t) {
            return Do(i.domain(), e, t);
        };
        i.nice = function() {
            return i.domain(Co(i.domain(), Oo));
        };
        i.exponent = function(e) {
            if (!arguments.length) return t;
            var s = i.domain();
            n = Uo(t = e);
            r = Uo(1 / t);
            return i.domain(s);
        };
        i.copy = function() {
            return Ro(e.copy(), t);
        };
        return Ao(i, e);
    }
    function Uo(e) {
        return function(t) {
            return t < 0 ? -Math.pow(-t, e) : Math.pow(t, e);
        };
    }
    function zo(t, n) {
        function o(e) {
            return i[((r.get(e) || r.set(e, t.push(e))) - 1) % i.length];
        }
        function u(n, r) {
            return e.range(t.length).map(function(e) {
                return n + r * e;
            });
        }
        var r, i, s;
        o.domain = function(e) {
            if (!arguments.length) return t;
            t = [];
            r = new c;
            var i = -1, s = e.length, u;
            while (++i < s) r.has(u = e[i]) || r.set(u, t.push(u));
            return o[n.t].apply(o, n.a);
        };
        o.range = function(e) {
            if (!arguments.length) return i;
            i = e;
            s = 0;
            n = {
                t: "range",
                a: arguments
            };
            return o;
        };
        o.rangePoints = function(e, r) {
            arguments.length < 2 && (r = 0);
            var a = e[0], f = e[1], l = (f - a) / (Math.max(1, t.length - 1) + r);
            i = u(t.length < 2 ? (a + f) / 2 : a + l * r / 2, l);
            s = 0;
            n = {
                t: "rangePoints",
                a: arguments
            };
            return o;
        };
        o.rangeBands = function(e, r, a) {
            arguments.length < 2 && (r = 0);
            arguments.length < 3 && (a = r);
            var f = e[1] < e[0], l = e[f - 0], c = e[1 - f], h = (c - l) / (t.length - r + 2 * a);
            i = u(l + h * a, h);
            f && i.reverse();
            s = h * (1 - r);
            n = {
                t: "rangeBands",
                a: arguments
            };
            return o;
        };
        o.rangeRoundBands = function(e, r, a) {
            arguments.length < 2 && (r = 0);
            arguments.length < 3 && (a = r);
            var f = e[1] < e[0], l = e[f - 0], c = e[1 - f], h = Math.floor((c - l) / (t.length - r + 2 * a)), p = c - l - (t.length - r) * h;
            i = u(l + Math.round(p / 2), h);
            f && i.reverse();
            s = Math.round(h * (1 - r));
            n = {
                t: "rangeRoundBands",
                a: arguments
            };
            return o;
        };
        o.rangeBand = function() {
            return s;
        };
        o.rangeExtent = function() {
            return xo(n.a[0]);
        };
        o.copy = function() {
            return zo(t, n);
        };
        return o.domain(t);
    }
    function Jo(t, n) {
        function i() {
            var i = 0, o = n.length;
            r = [];
            while (++i < o) r[i - 1] = e.quantile(t, i / o);
            return s;
        }
        function s(t) {
            return isNaN(t = +t) ? NaN : n[e.bisect(r, t)];
        }
        var r;
        s.domain = function(n) {
            if (!arguments.length) return t;
            t = n.filter(function(e) {
                return !isNaN(e);
            }).sort(e.ascending);
            return i();
        };
        s.range = function(e) {
            if (!arguments.length) return n;
            n = e;
            return i();
        };
        s.quantiles = function() {
            return r;
        };
        s.copy = function() {
            return Jo(t, n);
        };
        return i();
    }
    function Ko(e, t, n) {
        function s(t) {
            return n[Math.max(0, Math.min(i, Math.floor(r * (t - e))))];
        }
        function o() {
            r = n.length / (t - e);
            i = n.length - 1;
            return s;
        }
        var r, i;
        s.domain = function(n) {
            if (!arguments.length) return [ e, t ];
            e = +n[0];
            t = +n[n.length - 1];
            return o();
        };
        s.range = function(e) {
            if (!arguments.length) return n;
            n = e;
            return o();
        };
        s.copy = function() {
            return Ko(e, t, n);
        };
        return o();
    }
    function Qo(t, n) {
        function r(r) {
            return n[e.bisect(t, r)];
        }
        r.domain = function(e) {
            if (!arguments.length) return t;
            t = e;
            return r;
        };
        r.range = function(e) {
            if (!arguments.length) return n;
            n = e;
            return r;
        };
        r.copy = function() {
            return Qo(t, n);
        };
        return r;
    }
    function Go(e) {
        function t(e) {
            return +e;
        }
        t.invert = t;
        t.domain = t.range = function(n) {
            if (!arguments.length) return e;
            e = n.map(t);
            return t;
        };
        t.ticks = function(t) {
            return _o(e, t);
        };
        t.tickFormat = function(t, n) {
            return Do(e, t, n);
        };
        t.copy = function() {
            return Go(e);
        };
        return t;
    }
    function eu(e) {
        return e.innerRadius;
    }
    function tu(e) {
        return e.outerRadius;
    }
    function nu(e) {
        return e.startAngle;
    }
    function ru(e) {
        return e.endAngle;
    }
    function iu(e) {
        var t, n = -1, r = e.length, i, s;
        while (++n < r) {
            t = e[n];
            i = t[0];
            s = t[1] + Yo;
            t[0] = i * Math.cos(s);
            t[1] = i * Math.sin(s);
        }
        return e;
    }
    function su(e) {
        function c(u) {
            function x() {
                c.push("M", o(e(p), l), f, a(e(h.reverse()), l), "Z");
            }
            var c = [], h = [], p = [], d = -1, v = u.length, m, g = Qt(t), y = Qt(r), b = t === n ? function() {
                return E;
            } : Qt(n), w = r === i ? function() {
                return S;
            } : Qt(i), E, S;
            while (++d < v) if (s.call(this, m = u[d], d)) {
                h.push([ E = +g.call(this, m, d), S = +y.call(this, m, d) ]);
                p.push([ +b.call(this, m, d), +w.call(this, m, d) ]);
            } else if (h.length) {
                x();
                h = [];
                p = [];
            }
            h.length && x();
            return c.length ? c.join("") : null;
        }
        var t = si, n = si, r = 0, i = oi, s = $n, o = ai, u = o.key, a = o, f = "L", l = .7;
        c.x = function(e) {
            if (!arguments.length) return n;
            t = n = e;
            return c;
        };
        c.x0 = function(e) {
            if (!arguments.length) return t;
            t = e;
            return c;
        };
        c.x1 = function(e) {
            if (!arguments.length) return n;
            n = e;
            return c;
        };
        c.y = function(e) {
            if (!arguments.length) return i;
            r = i = e;
            return c;
        };
        c.y0 = function(e) {
            if (!arguments.length) return r;
            r = e;
            return c;
        };
        c.y1 = function(e) {
            if (!arguments.length) return i;
            i = e;
            return c;
        };
        c.defined = function(e) {
            if (!arguments.length) return s;
            s = e;
            return c;
        };
        c.interpolate = function(e) {
            if (!arguments.length) return u;
            typeof e == "function" ? u = o = e : u = (o = ui.get(e) || ai).key;
            a = o.reverse || o;
            f = o.closed ? "M" : "L";
            return c;
        };
        c.tension = function(e) {
            if (!arguments.length) return l;
            l = e;
            return c;
        };
        return c;
    }
    function ou(e) {
        return e.radius;
    }
    function uu(e) {
        return [ e.x, e.y ];
    }
    function au(e) {
        return function() {
            var t = e.apply(this, arguments), n = t[0], r = t[1] + Yo;
            return [ n * Math.cos(r), n * Math.sin(r) ];
        };
    }
    function fu() {
        return 64;
    }
    function lu() {
        return "circle";
    }
    function cu(e) {
        var t = Math.sqrt(e / dt);
        return "M0," + t + "A" + t + "," + t + " 0 1,1 0," + -t + "A" + t + "," + t + " 0 1,1 0," + t + "Z";
    }
    function vu(e, t) {
        A(e, mu);
        e.id = t;
        return e;
    }
    function wu(e, t, n, r) {
        var i = e.id;
        return nt(e, typeof n == "function" ? function(e, s, o) {
            e.__transition__[i].tween.set(t, r(n.call(e, e.__data__, s, o)));
        } : (n = r(n), function(e) {
            e.__transition__[i].tween.set(t, n);
        }));
    }
    function Eu(e) {
        e == null && (e = "");
        return function() {
            this.textContent = e;
        };
    }
    function Su(t, n, r, i) {
        var s = t.__transition__ || (t.__transition__ = {
            active: 0,
            count: 0
        }), o = s[r];
        if (!o) {
            var u = i.time;
            o = s[r] = {
                tween: new c,
                event: e.dispatch("start", "end"),
                time: u,
                ease: i.ease,
                delay: i.delay,
                duration: i.duration
            };
            ++s.count;
            e.timer(function(i) {
                function d(i) {
                    if (s.active > r) return m();
                    s.active = r;
                    l.start.call(t, a, n);
                    o.tween.forEach(function(e, r) {
                        (r = r.call(t, a, n)) && p.push(r);
                    });
                    v(i) || e.timer(v, 0, u);
                    return 1;
                }
                function v(e) {
                    if (s.active !== r) return m();
                    var i = (e - c) / h, o = f(i), u = p.length;
                    while (u > 0) p[--u].call(t, o);
                    if (i >= 1) {
                        m();
                        l.end.call(t, a, n);
                        return 1;
                    }
                }
                function m() {
                    --s.count ? delete s[r] : delete t.__transition__;
                    return 1;
                }
                var a = t.__data__, f = o.ease, l = o.event, c = o.delay, h = o.duration, p = [];
                return c <= i ? d(i) : e.timer(d, c, u), 1;
            }, 0, u);
            return o;
        }
    }
    function Nu(e, t) {
        e.attr("transform", function(e) {
            return "translate(" + t(e) + ",0)";
        });
    }
    function Cu(e, t) {
        e.attr("transform", function(e) {
            return "translate(0," + t(e) + ")";
        });
    }
    function ku(e, t, n) {
        i = [];
        if (n && t.length > 1) {
            var r = xo(e.domain()), i, s = -1, o = t.length, u = (t[1] - t[0]) / ++n, a, f;
            while (++s < o) for (a = n; --a > 0; ) (f = +t[s] - a * u) >= r[0] && i.push(f);
            for (--s, a = 0; ++a < n && (f = +t[s] + a * u) < r[1]; ) i.push(f);
        }
        return i;
    }
    function _u() {
        this._ = new Date(arguments.length > 1 ? Date.UTC.apply(this, arguments) : arguments[0]);
    }
    function Ru(e, t, n) {
        function r(t) {
            var n = e(t), r = s(n, 1);
            return t - n < r - t ? n : r;
        }
        function i(n) {
            t(n = e(new Ou(n - 1)), 1);
            return n;
        }
        function s(e, n) {
            t(e = new Ou(+e), n);
            return e;
        }
        function o(e, r, s) {
            var o = i(e), u = [];
            if (s > 1) while (o < r) {
                n(o) % s || u.push(new Date(+o));
                t(o, 1);
            } else while (o < r) u.push(new Date(+o)), t(o, 1);
            return u;
        }
        function u(e, t, n) {
            try {
                Ou = _u;
                var r = new _u;
                r._ = e;
                return o(r, t, n);
            } finally {
                Ou = Date;
            }
        }
        e.floor = e;
        e.round = r;
        e.ceil = i;
        e.offset = s;
        e.range = o;
        var a = e.utc = Uu(e);
        a.floor = a;
        a.round = Uu(r);
        a.ceil = Uu(i);
        a.offset = Uu(s);
        a.range = u;
        return e;
    }
    function Uu(e) {
        return function(t, n) {
            try {
                Ou = _u;
                var r = new _u;
                r._ = t;
                return e(r, n)._;
            } finally {
                Ou = Date;
            }
        };
    }
    function zu(e, t, n, r) {
        var i, s, o = 0, u = t.length, a = n.length;
        while (o < u) {
            if (r >= a) return -1;
            i = t.charCodeAt(o++);
            if (i === 37) {
                s = ta[t.charAt(o++)];
                if (!s || (r = s(e, n, r)) < 0) return -1;
            } else if (i != n.charCodeAt(r++)) return -1;
        }
        return r;
    }
    function Wu(t) {
        return new RegExp("^(?:" + t.map(e.requote).join("|") + ")", "i");
    }
    function Xu(e) {
        var t = new c, n = -1, r = e.length;
        while (++n < r) t.set(e[n].toLowerCase(), n);
        return t;
    }
    function Vu(e, t, n) {
        e += "";
        var r = e.length;
        return r < n ? (new Array(n - r + 1)).join(t) + e : e;
    }
    function na(e, t, n) {
        Ju.lastIndex = 0;
        var r = Ju.exec(t.substring(n));
        return r ? n += r[0].length : -1;
    }
    function ra(e, t, n) {
        $u.lastIndex = 0;
        var r = $u.exec(t.substring(n));
        return r ? n += r[0].length : -1;
    }
    function ia(e, t, n) {
        Gu.lastIndex = 0;
        var r = Gu.exec(t.substring(n));
        return r ? (e.m = Yu.get(r[0].toLowerCase()), n += r[0].length) : -1;
    }
    function sa(e, t, n) {
        Ku.lastIndex = 0;
        var r = Ku.exec(t.substring(n));
        return r ? (e.m = Qu.get(r[0].toLowerCase()), n += r[0].length) : -1;
    }
    function oa(e, t, n) {
        return zu(e, ea.c.toString(), t, n);
    }
    function ua(e, t, n) {
        return zu(e, ea.x.toString(), t, n);
    }
    function aa(e, t, n) {
        return zu(e, ea.X.toString(), t, n);
    }
    function fa(e, t, n) {
        ya.lastIndex = 0;
        var r = ya.exec(t.substring(n, n + 4));
        return r ? (e.y = +r[0], n += r[0].length) : -1;
    }
    function la(e, t, n) {
        ya.lastIndex = 0;
        var r = ya.exec(t.substring(n, n + 2));
        return r ? (e.y = ca(+r[0]), n += r[0].length) : -1;
    }
    function ca(e) {
        return e + (e > 68 ? 1900 : 2e3);
    }
    function ha(e, t, n) {
        ya.lastIndex = 0;
        var r = ya.exec(t.substring(n, n + 2));
        return r ? (e.m = r[0] - 1, n += r[0].length) : -1;
    }
    function pa(e, t, n) {
        ya.lastIndex = 0;
        var r = ya.exec(t.substring(n, n + 2));
        return r ? (e.d = +r[0], n += r[0].length) : -1;
    }
    function da(e, t, n) {
        ya.lastIndex = 0;
        var r = ya.exec(t.substring(n, n + 2));
        return r ? (e.H = +r[0], n += r[0].length) : -1;
    }
    function va(e, t, n) {
        ya.lastIndex = 0;
        var r = ya.exec(t.substring(n, n + 2));
        return r ? (e.M = +r[0], n += r[0].length) : -1;
    }
    function ma(e, t, n) {
        ya.lastIndex = 0;
        var r = ya.exec(t.substring(n, n + 2));
        return r ? (e.S = +r[0], n += r[0].length) : -1;
    }
    function ga(e, t, n) {
        ya.lastIndex = 0;
        var r = ya.exec(t.substring(n, n + 3));
        return r ? (e.L = +r[0], n += r[0].length) : -1;
    }
    function ba(e, t, n) {
        var r = wa.get(t.substring(n, n += 2).toLowerCase());
        return r == null ? -1 : (e.p = r, n);
    }
    function Ea(e) {
        var t = e.getTimezoneOffset(), n = t > 0 ? "-" : "+", r = ~~(Math.abs(t) / 60), i = Math.abs(t) % 60;
        return n + Vu(r, "0", 2) + Vu(i, "0", 2);
    }
    function xa(e) {
        return e.toISOString();
    }
    function Ta(t, n, r) {
        function i(e) {
            return t(e);
        }
        i.invert = function(e) {
            return Ca(t.invert(e));
        };
        i.domain = function(e) {
            if (!arguments.length) return t.domain().map(Ca);
            t.domain(e);
            return i;
        };
        i.nice = function(e) {
            return i.domain(Co(i.domain(), function() {
                return e;
            }));
        };
        i.ticks = function(r, s) {
            var o = Na(i.domain());
            if (typeof r != "function") {
                var u = o[1] - o[0], a = u / r, f = e.bisect(Oa, a);
                if (f == Oa.length) return n.year(o, r);
                if (!f) return t.ticks(r).map(Ca);
                Math.log(a / Oa[f - 1]) < Math.log(Oa[f] / a) && --f;
                r = n[f];
                s = r[1];
                r = r[0].range;
            }
            return r(o[0], new Date(+o[1] + 1), s);
        };
        i.tickFormat = function() {
            return r;
        };
        i.copy = function() {
            return Ta(t.copy(), n, r);
        };
        return e.rebind(i, t, "range", "rangeRound", "interpolate", "clamp");
    }
    function Na(e) {
        var t = e[0], n = e[e.length - 1];
        return t < n ? [ t, n ] : [ n, t ];
    }
    function Ca(e) {
        return new Date(e);
    }
    function ka(e) {
        return function(t) {
            var n = e.length - 1, r = e[n];
            while (!r[1](t)) r = e[--n];
            return r[0](t);
        };
    }
    function La(e) {
        var t = new Date(e, 0, 1);
        t.setFullYear(e);
        return t;
    }
    function Aa(e) {
        var t = e.getFullYear(), n = La(t), r = La(t + 1);
        return t + (e - n) / (r - n);
    }
    function Fa(e) {
        var t = new Date(Date.UTC(e, 0, 1));
        t.setUTCFullYear(e);
        return t;
    }
    function Ia(e) {
        var t = e.getUTCFullYear(), n = Fa(t), r = Fa(t + 1);
        return t + (e - n) / (r - n);
    }
    function qa(e) {
        return e.responseText;
    }
    function Ra(e) {
        return JSON.parse(e.responseText);
    }
    function Ua(e) {
        var n = t.createRange();
        n.selectNode(t.body);
        return n.createContextualFragment(e.responseText);
    }
    function za(e) {
        return e.responseXML;
    }
    var e = {
        version: "3.1.5"
    };
    Date.now || (Date.now = function() {
        return +(new Date);
    });
    var t = document, n = window;
    try {
        t.createElement("div").style.setProperty("opacity", 0, "");
    } catch (r) {
        var i = n.CSSStyleDeclaration.prototype, s = i.setProperty;
        i.setProperty = function(e, t, n) {
            s.call(this, e, t + "", n);
        };
    }
    e.ascending = function(e, t) {
        return e < t ? -1 : e > t ? 1 : e >= t ? 0 : NaN;
    };
    e.descending = function(e, t) {
        return t < e ? -1 : t > e ? 1 : t >= e ? 0 : NaN;
    };
    e.min = function(e, t) {
        var n = -1, r = e.length, i, s;
        if (arguments.length === 1) {
            while (++n < r && ((i = e[n]) == null || i != i)) i = undefined;
            while (++n < r) (s = e[n]) != null && i > s && (i = s);
        } else {
            while (++n < r && ((i = t.call(e, e[n], n)) == null || i != i)) i = undefined;
            while (++n < r) (s = t.call(e, e[n], n)) != null && i > s && (i = s);
        }
        return i;
    };
    e.max = function(e, t) {
        var n = -1, r = e.length, i, s;
        if (arguments.length === 1) {
            while (++n < r && ((i = e[n]) == null || i != i)) i = undefined;
            while (++n < r) (s = e[n]) != null && s > i && (i = s);
        } else {
            while (++n < r && ((i = t.call(e, e[n], n)) == null || i != i)) i = undefined;
            while (++n < r) (s = t.call(e, e[n], n)) != null && s > i && (i = s);
        }
        return i;
    };
    e.extent = function(e, t) {
        var n = -1, r = e.length, i, s, o;
        if (arguments.length === 1) {
            while (++n < r && ((i = o = e[n]) == null || i != i)) i = o = undefined;
            while (++n < r) if ((s = e[n]) != null) {
                i > s && (i = s);
                o < s && (o = s);
            }
        } else {
            while (++n < r && ((i = o = t.call(e, e[n], n)) == null || i != i)) i = undefined;
            while (++n < r) if ((s = t.call(e, e[n], n)) != null) {
                i > s && (i = s);
                o < s && (o = s);
            }
        }
        return [ i, o ];
    };
    e.sum = function(e, t) {
        var n = 0, r = e.length, i, s = -1;
        if (arguments.length === 1) while (++s < r) isNaN(i = +e[s]) || (n += i); else while (++s < r) isNaN(i = +t.call(e, e[s], s)) || (n += i);
        return n;
    };
    e.mean = function(e, t) {
        var n = e.length, r, i = 0, s = -1, u = 0;
        if (arguments.length === 1) while (++s < n) o(r = e[s]) && (i += (r - i) / ++u); else while (++s < n) o(r = t.call(e, e[s], s)) && (i += (r - i) / ++u);
        return u ? i : undefined;
    };
    e.quantile = function(e, t) {
        var n = (e.length - 1) * t + 1, r = Math.floor(n), i = +e[r - 1], s = n - r;
        return s ? i + s * (e[r] - i) : i;
    };
    e.median = function(t, n) {
        arguments.length > 1 && (t = t.map(n));
        t = t.filter(o);
        return t.length ? e.quantile(t.sort(e.ascending), .5) : undefined;
    };
    e.bisector = function(e) {
        return {
            left: function(t, n, r, i) {
                arguments.length < 3 && (r = 0);
                arguments.length < 4 && (i = t.length);
                while (r < i) {
                    var s = r + i >>> 1;
                    e.call(t, t[s], s) < n ? r = s + 1 : i = s;
                }
                return r;
            },
            right: function(t, n, r, i) {
                arguments.length < 3 && (r = 0);
                arguments.length < 4 && (i = t.length);
                while (r < i) {
                    var s = r + i >>> 1;
                    n < e.call(t, t[s], s) ? i = s : r = s + 1;
                }
                return r;
            }
        };
    };
    var u = e.bisector(function(e) {
        return e;
    });
    e.bisectLeft = u.left;
    e.bisect = e.bisectRight = u.right;
    e.shuffle = function(e) {
        var t = e.length, n, r;
        while (t) {
            r = Math.random() * t-- | 0;
            n = e[t], e[t] = e[r], e[r] = n;
        }
        return e;
    };
    e.permute = function(e, t) {
        var n = [], r = -1, i = t.length;
        while (++r < i) n[r] = e[t[r]];
        return n;
    };
    e.zip = function() {
        if (!(s = arguments.length)) return [];
        for (var t = -1, n = e.min(arguments, a), r = new Array(n); ++t < n; ) for (var i = -1, s, o = r[t] = new Array(s); ++i < s; ) o[i] = arguments[i][t];
        return r;
    };
    e.transpose = function(t) {
        return e.zip.apply(e, t);
    };
    e.keys = function(e) {
        var t = [];
        for (var n in e) t.push(n);
        return t;
    };
    e.values = function(e) {
        var t = [];
        for (var n in e) t.push(e[n]);
        return t;
    };
    e.entries = function(e) {
        var t = [];
        for (var n in e) t.push({
            key: n,
            value: e[n]
        });
        return t;
    };
    e.merge = function(e) {
        return Array.prototype.concat.apply([], e);
    };
    e.range = function(e, t, n) {
        if (arguments.length < 3) {
            n = 1;
            if (arguments.length < 2) {
                t = e;
                e = 0;
            }
        }
        if ((t - e) / n === Infinity) throw new Error("infinite range");
        var r = [], i = f(Math.abs(n)), s = -1, o;
        e *= i, t *= i, n *= i;
        if (n < 0) while ((o = e + n * ++s) > t) r.push(o / i); else while ((o = e + n * ++s) < t) r.push(o / i);
        return r;
    };
    e.map = function(e) {
        var t = new c;
        for (var n in e) t.set(n, e[n]);
        return t;
    };
    l(c, {
        has: function(e) {
            return h + e in this;
        },
        get: function(e) {
            return this[h + e];
        },
        set: function(e, t) {
            return this[h + e] = t;
        },
        remove: function(e) {
            e = h + e;
            return e in this && delete this[e];
        },
        keys: function() {
            var e = [];
            this.forEach(function(t) {
                e.push(t);
            });
            return e;
        },
        values: function() {
            var e = [];
            this.forEach(function(t, n) {
                e.push(n);
            });
            return e;
        },
        entries: function() {
            var e = [];
            this.forEach(function(t, n) {
                e.push({
                    key: t,
                    value: n
                });
            });
            return e;
        },
        forEach: function(e) {
            for (var t in this) t.charCodeAt(0) === p && e.call(this, t.substring(1), this[t]);
        }
    });
    var h = "\0", p = h.charCodeAt(0);
    e.nest = function() {
        function o(e, r, u) {
            if (u >= n.length) return s ? s.call(t, r) : i ? r.sort(i) : r;
            var a = -1, f = r.length, l = n[u++], h, p, d, v = new c, m;
            while (++a < f) (m = v.get(h = l(p = r[a]))) ? m.push(p) : v.set(h, [ p ]);
            if (e) {
                p = e();
                d = function(t, n) {
                    p.set(t, o(e, n, u));
                };
            } else {
                p = {};
                d = function(t, n) {
                    p[t] = o(e, n, u);
                };
            }
            v.forEach(d);
            return p;
        }
        function u(e, t) {
            if (t >= n.length) return e;
            var i = [], s = r[t++];
            e.forEach(function(e, n) {
                i.push({
                    key: e,
                    values: u(n, t)
                });
            });
            return s ? i.sort(function(e, t) {
                return s(e.key, t.key);
            }) : i;
        }
        var t = {}, n = [], r = [], i, s;
        t.map = function(e, t) {
            return o(t, e, 0);
        };
        t.entries = function(t) {
            return u(o(e.map, t, 0), 0);
        };
        t.key = function(e) {
            n.push(e);
            return t;
        };
        t.sortKeys = function(e) {
            r[n.length - 1] = e;
            return t;
        };
        t.sortValues = function(e) {
            i = e;
            return t;
        };
        t.rollup = function(e) {
            s = e;
            return t;
        };
        return t;
    };
    e.set = function(e) {
        var t = new d;
        if (e) for (var n = 0; n < e.length; n++) t.add(e[n]);
        return t;
    };
    l(d, {
        has: function(e) {
            return h + e in this;
        },
        add: function(e) {
            this[h + e] = !0;
            return e;
        },
        remove: function(e) {
            e = h + e;
            return e in this && delete this[e];
        },
        values: function() {
            var e = [];
            this.forEach(function(t) {
                e.push(t);
            });
            return e;
        },
        forEach: function(e) {
            for (var t in this) t.charCodeAt(0) === p && e.call(this, t.substring(1));
        }
    });
    e.behavior = {};
    e.rebind = function(e, t) {
        var n = 1, r = arguments.length, i;
        while (++n < r) e[i = arguments[n]] = v(e, t, t[i]);
        return e;
    };
    e.dispatch = function() {
        var e = new m, t = -1, n = arguments.length;
        while (++t < n) e[arguments[t]] = g(e);
        return e;
    };
    m.prototype.on = function(e, t) {
        var n = e.indexOf("."), r = "";
        if (n >= 0) {
            r = e.substring(n + 1);
            e = e.substring(0, n);
        }
        if (e) return arguments.length < 2 ? this[e].on(r) : this[e].on(r, t);
        if (arguments.length === 2) {
            if (t == null) for (e in this) this.hasOwnProperty(e) && this[e].on(r, null);
            return this;
        }
    };
    e.event = null;
    e.mouse = function(e) {
        return T(e, w());
    };
    var x = /WebKit/.test(n.navigator.userAgent) ? -1 : 0, N = k;
    try {
        N(t.documentElement.childNodes)[0].nodeType;
    } catch (L) {
        N = C;
    }
    var A = [].__proto__ ? function(e, t) {
        e.__proto__ = t;
    } : function(e, t) {
        for (var n in t) e[n] = t[n];
    };
    e.touches = function(e, t) {
        arguments.length < 2 && (t = w().touches);
        return t ? N(t).map(function(t) {
            var n = T(e, t);
            n.identifier = t.identifier;
            return n;
        }) : [];
    };
    e.behavior.drag = function() {
        function i() {
            this.on("mousedown.drag", s).on("touchstart.drag", s);
        }
        function s() {
            function h() {
                var t = i.parentNode;
                return u != null ? e.touches(t).filter(function(e) {
                    return e.identifier === u;
                })[0] : e.mouse(t);
            }
            function p() {
                if (!i.parentNode) return d();
                var e = h(), t = e[0] - f[0], n = e[1] - f[1];
                l |= t | n;
                f = e;
                y();
                s({
                    type: "drag",
                    x: e[0] + a[0],
                    y: e[1] + a[1],
                    dx: t,
                    dy: n
                });
            }
            function d() {
                s({
                    type: "dragend"
                });
                if (l) {
                    y();
                    e.event.target === o && E(c, "click");
                }
                c.on(u != null ? "touchmove.drag-" + u : "mousemove.drag", null).on(u != null ? "touchend.drag-" + u : "mouseup.drag", null);
            }
            var i = this, s = t.of(i, arguments), o = e.event.target, u = e.event.touches ? e.event.changedTouches[0].identifier : null, a, f = h(), l = 0, c = e.select(n).on(u != null ? "touchmove.drag-" + u : "mousemove.drag", p).on(u != null ? "touchend.drag-" + u : "mouseup.drag", d, !0);
            if (r) {
                a = r.apply(i, arguments);
                a = [ a.x - f[0], a.y - f[1] ];
            } else a = [ 0, 0 ];
            u == null && y();
            s({
                type: "dragstart"
            });
        }
        var t = S(i, "drag", "dragstart", "dragend"), r = null;
        i.origin = function(e) {
            if (!arguments.length) return r;
            r = e;
            return i;
        };
        return e.rebind(i, t, "on");
    };
    var M = function(e, t) {
        return t.querySelector(e);
    }, _ = function(e, t) {
        return t.querySelectorAll(e);
    }, D = t.documentElement, P = D.matchesSelector || D.webkitMatchesSelector || D.mozMatchesSelector || D.msMatchesSelector || D.oMatchesSelector, H = function(e, t) {
        return P.call(e, t);
    };
    if (typeof Sizzle == "function") {
        M = function(e, t) {
            return Sizzle(e, t)[0] || null;
        };
        _ = function(e, t) {
            return Sizzle.uniqueSort(Sizzle(e, t));
        };
        H = Sizzle.matchesSelector;
    }
    var B = [];
    e.selection = function() {
        return st;
    };
    e.selection.prototype = B;
    B.select = function(e) {
        var t = [], n, r, i, s;
        typeof e != "function" && (e = j(e));
        for (var o = -1, u = this.length; ++o < u; ) {
            t.push(n = []);
            n.parentNode = (i = this[o]).parentNode;
            for (var a = -1, f = i.length; ++a < f; ) if (s = i[a]) {
                n.push(r = e.call(s, s.__data__, a));
                r && "__data__" in s && (r.__data__ = s.__data__);
            } else n.push(null);
        }
        return O(t);
    };
    B.selectAll = function(e) {
        var t = [], n, r;
        typeof e != "function" && (e = F(e));
        for (var i = -1, s = this.length; ++i < s; ) for (var o = this[i], u = -1, a = o.length; ++u < a; ) if (r = o[u]) {
            t.push(n = N(e.call(r, r.__data__, u)));
            n.parentNode = r;
        }
        return O(t);
    };
    var I = {
        svg: "http://www.w3.org/2000/svg",
        xhtml: "http://www.w3.org/1999/xhtml",
        xlink: "http://www.w3.org/1999/xlink",
        xml: "http://www.w3.org/XML/1998/namespace",
        xmlns: "http://www.w3.org/2000/xmlns/"
    };
    e.ns = {
        prefix: I,
        qualify: function(e) {
            var t = e.indexOf(":"), n = e;
            if (t >= 0) {
                n = e.substring(0, t);
                e = e.substring(t + 1);
            }
            return I.hasOwnProperty(n) ? {
                space: I[n],
                local: e
            } : e;
        }
    };
    B.attr = function(t, n) {
        if (arguments.length < 2) {
            if (typeof t == "string") {
                var r = this.node();
                t = e.ns.qualify(t);
                return t.local ? r.getAttributeNS(t.space, t.local) : r.getAttribute(t);
            }
            for (n in t) this.each(q(n, t[n]));
            return this;
        }
        return this.each(q(t, n));
    };
    e.requote = function(e) {
        return e.replace(U, "\\$&");
    };
    var U = /[\\\^\$\*\+\?\|\[\]\(\)\.\{\}]/g;
    B.classed = function(e, t) {
        if (arguments.length < 2) {
            if (typeof e == "string") {
                var n = this.node(), r = (e = e.trim().split(/^|\s+/g)).length, i = -1;
                if (t = n.classList) {
                    while (++i < r) if (!t.contains(e[i])) return !1;
                } else {
                    t = n.getAttribute("class");
                    while (++i < r) if (!z(e[i]).test(t)) return !1;
                }
                return !0;
            }
            for (t in e) this.each(W(t, e[t]));
            return this;
        }
        return this.each(W(e, t));
    };
    B.style = function(e, t, r) {
        var i = arguments.length;
        if (i < 3) {
            if (typeof e != "string") {
                i < 2 && (t = "");
                for (r in e) this.each(V(r, e[r], t));
                return this;
            }
            if (i < 2) return n.getComputedStyle(this.node(), null).getPropertyValue(e);
            r = "";
        }
        return this.each(V(e, t, r));
    };
    B.property = function(e, t) {
        if (arguments.length < 2) {
            if (typeof e == "string") return this.node()[e];
            for (t in e) this.each($(t, e[t]));
            return this;
        }
        return this.each($(e, t));
    };
    B.text = function(e) {
        return arguments.length ? this.each(typeof e == "function" ? function() {
            var t = e.apply(this, arguments);
            this.textContent = t == null ? "" : t;
        } : e == null ? function() {
            this.textContent = "";
        } : function() {
            this.textContent = e;
        }) : this.node().textContent;
    };
    B.html = function(e) {
        return arguments.length ? this.each(typeof e == "function" ? function() {
            var t = e.apply(this, arguments);
            this.innerHTML = t == null ? "" : t;
        } : e == null ? function() {
            this.innerHTML = "";
        } : function() {
            this.innerHTML = e;
        }) : this.node().innerHTML;
    };
    B.append = function(n) {
        function r() {
            return this.appendChild(t.createElementNS(this.namespaceURI, n));
        }
        function i() {
            return this.appendChild(t.createElementNS(n.space, n.local));
        }
        n = e.ns.qualify(n);
        return this.select(n.local ? i : r);
    };
    B.insert = function(n, r) {
        function i(e, i) {
            return this.insertBefore(t.createElementNS(this.namespaceURI, n), r.call(this, e, i));
        }
        function s(e, i) {
            return this.insertBefore(t.createElementNS(n.space, n.local), r.call(this, e, i));
        }
        n = e.ns.qualify(n);
        typeof r != "function" && (r = j(r));
        return this.select(n.local ? s : i);
    };
    B.remove = function() {
        return this.each(function() {
            var e = this.parentNode;
            e && e.removeChild(this);
        });
    };
    B.data = function(e, t) {
        function o(e, n) {
            var r, i = e.length, s = n.length, o = Math.min(i, s), l = new Array(s), h = new Array(s), p = new Array(i), d, v;
            if (t) {
                var m = new c, g = new c, y = [], b;
                for (r = -1; ++r < i; ) {
                    b = t.call(d = e[r], d.__data__, r);
                    m.has(b) ? p[r] = d : m.set(b, d);
                    y.push(b);
                }
                for (r = -1; ++r < s; ) {
                    b = t.call(n, v = n[r], r);
                    if (d = m.get(b)) {
                        l[r] = d;
                        d.__data__ = v;
                    } else g.has(b) || (h[r] = J(v));
                    g.set(b, v);
                    m.remove(b);
                }
                for (r = -1; ++r < i; ) m.has(y[r]) && (p[r] = e[r]);
            } else {
                for (r = -1; ++r < o; ) {
                    d = e[r];
                    v = n[r];
                    if (d) {
                        d.__data__ = v;
                        l[r] = d;
                    } else h[r] = J(v);
                }
                for (; r < s; ++r) h[r] = J(n[r]);
                for (; r < i; ++r) p[r] = e[r];
            }
            h.update = l;
            h.parentNode = l.parentNode = p.parentNode = e.parentNode;
            u.push(h);
            a.push(l);
            f.push(p);
        }
        var n = -1, r = this.length, i, s;
        if (!arguments.length) {
            e = new Array(r = (i = this[0]).length);
            while (++n < r) if (s = i[n]) e[n] = s.__data__;
            return e;
        }
        var u = rt([]), a = O([]), f = O([]);
        if (typeof e == "function") while (++n < r) o(i = this[n], e.call(i, i.parentNode.__data__, n)); else while (++n < r) o(i = this[n], e);
        a.enter = function() {
            return u;
        };
        a.exit = function() {
            return f;
        };
        return a;
    };
    B.datum = function(e) {
        return arguments.length ? this.property("__data__", e) : this.property("__data__");
    };
    B.filter = function(e) {
        var t = [], n, r, i;
        typeof e != "function" && (e = K(e));
        for (var s = 0, o = this.length; s < o; s++) {
            t.push(n = []);
            n.parentNode = (r = this[s]).parentNode;
            for (var u = 0, a = r.length; u < a; u++) (i = r[u]) && e.call(i, i.__data__, u) && n.push(i);
        }
        return O(t);
    };
    B.order = function() {
        for (var e = -1, t = this.length; ++e < t; ) for (var n = this[e], r = n.length - 1, i = n[r], s; --r >= 0; ) if (s = n[r]) {
            i && i !== s.nextSibling && i.parentNode.insertBefore(s, i);
            i = s;
        }
        return this;
    };
    B.sort = function(e) {
        e = Q.apply(this, arguments);
        for (var t = -1, n = this.length; ++t < n; ) this[t].sort(e);
        return this.order();
    };
    B.on = function(e, t, n) {
        var r = arguments.length;
        if (r < 3) {
            if (typeof e != "string") {
                r < 2 && (t = !1);
                for (n in e) this.each(Y(n, e[n], t));
                return this;
            }
            if (r < 2) return (r = this.node()["__on" + e]) && r._;
            n = !1;
        }
        return this.each(Y(e, t, n));
    };
    var Z = e.map({
        mouseenter: "mouseover",
        mouseleave: "mouseout"
    });
    Z.forEach(function(e) {
        "on" + e in t && Z.remove(e);
    });
    B.each = function(e) {
        return nt(this, function(t, n, r) {
            e.call(t, t.__data__, n, r);
        });
    };
    B.call = function(e) {
        var t = N(arguments);
        e.apply(t[0] = this, t);
        return this;
    };
    B.empty = function() {
        return !this.node();
    };
    B.node = function() {
        for (var e = 0, t = this.length; e < t; e++) for (var n = this[e], r = 0, i = n.length; r < i; r++) {
            var s = n[r];
            if (s) return s;
        }
        return null;
    };
    var it = [];
    e.selection.enter = rt;
    e.selection.enter.prototype = it;
    it.append = B.append;
    it.insert = B.insert;
    it.empty = B.empty;
    it.node = B.node;
    it.select = function(e) {
        var t = [], n, r, i, s, o;
        for (var u = -1, a = this.length; ++u < a; ) {
            i = (s = this[u]).update;
            t.push(n = []);
            n.parentNode = s.parentNode;
            for (var f = -1, l = s.length; ++f < l; ) if (o = s[f]) {
                n.push(i[f] = r = e.call(s.parentNode, o.__data__, f));
                r.__data__ = o.__data__;
            } else n.push(null);
        }
        return O(t);
    };
    B.transition = function() {
        var e = yu || ++gu, t = [], n, r, i = Object.create(bu);
        i.time = Date.now();
        for (var s = -1, o = this.length; ++s < o; ) {
            t.push(n = []);
            for (var u = this[s], a = -1, f = u.length; ++a < f; ) {
                (r = u[a]) && Su(r, a, e, i);
                n.push(r);
            }
        }
        return vu(t, e);
    };
    var st = O([ [ t ] ]);
    st[0].parentNode = D;
    e.select = function(e) {
        return typeof e == "string" ? st.select(e) : O([ [ e ] ]);
    };
    e.selectAll = function(e) {
        return typeof e == "string" ? st.selectAll(e) : O([ N(e) ]);
    };
    e.behavior.zoom = function() {
        function p() {
            this.on("mousedown.zoom", x).on("mousemove.zoom", N).on(at + ".zoom", T).on("dblclick.zoom", C).on("touchstart.zoom", k).on("touchmove.zoom", L).on("touchend.zoom", k);
        }
        function d(e) {
            return [ (e[0] - t[0]) / i, (e[1] - t[1]) / i ];
        }
        function v(e) {
            return [ e[0] * i + t[0], e[1] * i + t[1] ];
        }
        function m(e) {
            i = Math.max(o[0], Math.min(o[1], e));
        }
        function g(e, n) {
            n = v(n);
            t[0] += e[0] - n[0];
            t[1] += e[1] - n[1];
        }
        function b() {
            f && f.domain(a.range().map(function(e) {
                return (e - t[0]) / i;
            }).map(a.invert));
            c && c.domain(l.range().map(function(e) {
                return (e - t[1]) / i;
            }).map(l.invert));
        }
        function w(n) {
            b();
            e.event.preventDefault();
            n({
                type: "zoom",
                scale: i,
                translate: t
            });
        }
        function x() {
            function f() {
                s = 1;
                g(e.mouse(t), a);
                w(r);
            }
            function l() {
                s && y();
                o.on("mousemove.zoom", null).on("mouseup.zoom", null);
                s && e.event.target === i && E(o, "click.zoom");
            }
            var t = this, r = u.of(t, arguments), i = e.event.target, s = 0, o = e.select(n).on("mousemove.zoom", f).on("mouseup.zoom", l), a = d(e.mouse(t));
            n.focus();
            y();
        }
        function T() {
            r || (r = d(e.mouse(this)));
            m(Math.pow(2, ut() * .002) * i);
            g(e.mouse(this), r);
            w(u.of(this, arguments));
        }
        function N() {
            r = null;
        }
        function C() {
            var t = e.mouse(this), n = d(t), r = Math.log(i) / Math.LN2;
            m(Math.pow(2, e.event.shiftKey ? Math.ceil(r) - 1 : Math.floor(r) + 1));
            g(t, n);
            w(u.of(this, arguments));
        }
        function k() {
            var t = e.touches(this), n = Date.now();
            s = i;
            r = {};
            t.forEach(function(e) {
                r[e.identifier] = d(e);
            });
            y();
            if (t.length === 1) {
                if (n - h < 500) {
                    var o = t[0], a = d(t[0]);
                    m(i * 2);
                    g(o, a);
                    w(u.of(this, arguments));
                }
                h = n;
            }
        }
        function L() {
            var t = e.touches(this), n = t[0], i = r[n.identifier];
            if (o = t[1]) {
                var o, a = r[o.identifier];
                n = [ (n[0] + o[0]) / 2, (n[1] + o[1]) / 2 ];
                i = [ (i[0] + a[0]) / 2, (i[1] + a[1]) / 2 ];
                m(e.event.scale * s);
            }
            g(n, i);
            h = null;
            w(u.of(this, arguments));
        }
        var t = [ 0, 0 ], r, i = 1, s, o = ot, u = S(p, "zoom"), a, f, l, c, h;
        p.translate = function(e) {
            if (!arguments.length) return t;
            t = e.map(Number);
            b();
            return p;
        };
        p.scale = function(e) {
            if (!arguments.length) return i;
            i = +e;
            b();
            return p;
        };
        p.scaleExtent = function(e) {
            if (!arguments.length) return o;
            o = e == null ? ot : e.map(Number);
            return p;
        };
        p.x = function(e) {
            if (!arguments.length) return f;
            f = e;
            a = e.copy();
            t = [ 0, 0 ];
            i = 1;
            return p;
        };
        p.y = function(e) {
            if (!arguments.length) return c;
            c = e;
            l = e.copy();
            t = [ 0, 0 ];
            i = 1;
            return p;
        };
        return e.rebind(p, u, "on");
    };
    var ot = [ 0, Infinity ], ut, at = "onwheel" in t ? (ut = function() {
        return -e.event.deltaY * (e.event.deltaMode ? 120 : 1);
    }, "wheel") : "onmousewheel" in t ? (ut = function() {
        return e.event.wheelDelta;
    }, "mousewheel") : (ut = function() {
        return -e.event.detail;
    }, "MozMousePixelScroll");
    ft.prototype.toString = function() {
        return this.rgb() + "";
    };
    e.hsl = function(e, t, n) {
        return arguments.length === 1 ? e instanceof ct ? lt(e.h, e.s, e.l) : Wt("" + e, Xt, lt) : lt(+e, +t, +n);
    };
    var ht = ct.prototype = new ft;
    ht.brighter = function(e) {
        e = Math.pow(.7, arguments.length ? e : 1);
        return lt(this.h, this.s, this.l / e);
    };
    ht.darker = function(e) {
        e = Math.pow(.7, arguments.length ? e : 1);
        return lt(this.h, this.s, e * this.l);
    };
    ht.rgb = function() {
        return pt(this.h, this.s, this.l);
    };
    var dt = Math.PI, vt = 1e-6, mt = dt / 180, gt = 180 / dt;
    e.hcl = function(t, n, r) {
        return arguments.length === 1 ? t instanceof Nt ? Tt(t.h, t.c, t.l) : t instanceof At ? Bt(t.l, t.a, t.b) : Bt((t = Vt((t = e.rgb(t)).r, t.g, t.b)).l, t.a, t.b) : Tt(+t, +n, +r);
    };
    var Ct = Nt.prototype = new ft;
    Ct.brighter = function(e) {
        return Tt(this.h, this.c, Math.min(100, this.l + Ot * (arguments.length ? e : 1)));
    };
    Ct.darker = function(e) {
        return Tt(this.h, this.c, Math.max(0, this.l - Ot * (arguments.length ? e : 1)));
    };
    Ct.rgb = function() {
        return kt(this.h, this.c, this.l).rgb();
    };
    e.lab = function(t, n, r) {
        return arguments.length === 1 ? t instanceof At ? Lt(t.l, t.a, t.b) : t instanceof Nt ? kt(t.l, t.c, t.h) : Vt((t = e.rgb(t)).r, t.g, t.b) : Lt(+t, +n, +r);
    };
    var Ot = 18, Mt = .95047, _t = 1, Dt = 1.08883, Pt = At.prototype = new ft;
    Pt.brighter = function(e) {
        return Lt(Math.min(100, this.l + Ot * (arguments.length ? e : 1)), this.a, this.b);
    };
    Pt.darker = function(e) {
        return Lt(Math.max(0, this.l - Ot * (arguments.length ? e : 1)), this.a, this.b);
    };
    Pt.rgb = function() {
        return Ht(this.l, this.a, this.b);
    };
    e.rgb = function(e, t, n) {
        return arguments.length === 1 ? e instanceof Rt ? qt(e.r, e.g, e.b) : Wt("" + e, qt, pt) : qt(~~e, ~~t, ~~n);
    };
    var Ut = Rt.prototype = new ft;
    Ut.brighter = function(e) {
        e = Math.pow(.7, arguments.length ? e : 1);
        var t = this.r, n = this.g, r = this.b, i = 30;
        if (!t && !n && !r) return qt(i, i, i);
        t && t < i && (t = i);
        n && n < i && (n = i);
        r && r < i && (r = i);
        return qt(Math.min(255, Math.floor(t / e)), Math.min(255, Math.floor(n / e)), Math.min(255, Math.floor(r / e)));
    };
    Ut.darker = function(e) {
        e = Math.pow(.7, arguments.length ? e : 1);
        return qt(Math.floor(e * this.r), Math.floor(e * this.g), Math.floor(e * this.b));
    };
    Ut.hsl = function() {
        return Xt(this.r, this.g, this.b);
    };
    Ut.toString = function() {
        return "#" + zt(this.r) + zt(this.g) + zt(this.b);
    };
    var Kt = e.map({
        aliceblue: "#f0f8ff",
        antiquewhite: "#faebd7",
        aqua: "#00ffff",
        aquamarine: "#7fffd4",
        azure: "#f0ffff",
        beige: "#f5f5dc",
        bisque: "#ffe4c4",
        black: "#000000",
        blanchedalmond: "#ffebcd",
        blue: "#0000ff",
        blueviolet: "#8a2be2",
        brown: "#a52a2a",
        burlywood: "#deb887",
        cadetblue: "#5f9ea0",
        chartreuse: "#7fff00",
        chocolate: "#d2691e",
        coral: "#ff7f50",
        cornflowerblue: "#6495ed",
        cornsilk: "#fff8dc",
        crimson: "#dc143c",
        cyan: "#00ffff",
        darkblue: "#00008b",
        darkcyan: "#008b8b",
        darkgoldenrod: "#b8860b",
        darkgray: "#a9a9a9",
        darkgreen: "#006400",
        darkgrey: "#a9a9a9",
        darkkhaki: "#bdb76b",
        darkmagenta: "#8b008b",
        darkolivegreen: "#556b2f",
        darkorange: "#ff8c00",
        darkorchid: "#9932cc",
        darkred: "#8b0000",
        darksalmon: "#e9967a",
        darkseagreen: "#8fbc8f",
        darkslateblue: "#483d8b",
        darkslategray: "#2f4f4f",
        darkslategrey: "#2f4f4f",
        darkturquoise: "#00ced1",
        darkviolet: "#9400d3",
        deeppink: "#ff1493",
        deepskyblue: "#00bfff",
        dimgray: "#696969",
        dimgrey: "#696969",
        dodgerblue: "#1e90ff",
        firebrick: "#b22222",
        floralwhite: "#fffaf0",
        forestgreen: "#228b22",
        fuchsia: "#ff00ff",
        gainsboro: "#dcdcdc",
        ghostwhite: "#f8f8ff",
        gold: "#ffd700",
        goldenrod: "#daa520",
        gray: "#808080",
        green: "#008000",
        greenyellow: "#adff2f",
        grey: "#808080",
        honeydew: "#f0fff0",
        hotpink: "#ff69b4",
        indianred: "#cd5c5c",
        indigo: "#4b0082",
        ivory: "#fffff0",
        khaki: "#f0e68c",
        lavender: "#e6e6fa",
        lavenderblush: "#fff0f5",
        lawngreen: "#7cfc00",
        lemonchiffon: "#fffacd",
        lightblue: "#add8e6",
        lightcoral: "#f08080",
        lightcyan: "#e0ffff",
        lightgoldenrodyellow: "#fafad2",
        lightgray: "#d3d3d3",
        lightgreen: "#90ee90",
        lightgrey: "#d3d3d3",
        lightpink: "#ffb6c1",
        lightsalmon: "#ffa07a",
        lightseagreen: "#20b2aa",
        lightskyblue: "#87cefa",
        lightslategray: "#778899",
        lightslategrey: "#778899",
        lightsteelblue: "#b0c4de",
        lightyellow: "#ffffe0",
        lime: "#00ff00",
        limegreen: "#32cd32",
        linen: "#faf0e6",
        magenta: "#ff00ff",
        maroon: "#800000",
        mediumaquamarine: "#66cdaa",
        mediumblue: "#0000cd",
        mediumorchid: "#ba55d3",
        mediumpurple: "#9370db",
        mediumseagreen: "#3cb371",
        mediumslateblue: "#7b68ee",
        mediumspringgreen: "#00fa9a",
        mediumturquoise: "#48d1cc",
        mediumvioletred: "#c71585",
        midnightblue: "#191970",
        mintcream: "#f5fffa",
        mistyrose: "#ffe4e1",
        moccasin: "#ffe4b5",
        navajowhite: "#ffdead",
        navy: "#000080",
        oldlace: "#fdf5e6",
        olive: "#808000",
        olivedrab: "#6b8e23",
        orange: "#ffa500",
        orangered: "#ff4500",
        orchid: "#da70d6",
        palegoldenrod: "#eee8aa",
        palegreen: "#98fb98",
        paleturquoise: "#afeeee",
        palevioletred: "#db7093",
        papayawhip: "#ffefd5",
        peachpuff: "#ffdab9",
        peru: "#cd853f",
        pink: "#ffc0cb",
        plum: "#dda0dd",
        powderblue: "#b0e0e6",
        purple: "#800080",
        red: "#ff0000",
        rosybrown: "#bc8f8f",
        royalblue: "#4169e1",
        saddlebrown: "#8b4513",
        salmon: "#fa8072",
        sandybrown: "#f4a460",
        seagreen: "#2e8b57",
        seashell: "#fff5ee",
        sienna: "#a0522d",
        silver: "#c0c0c0",
        skyblue: "#87ceeb",
        slateblue: "#6a5acd",
        slategray: "#708090",
        slategrey: "#708090",
        snow: "#fffafa",
        springgreen: "#00ff7f",
        steelblue: "#4682b4",
        tan: "#d2b48c",
        teal: "#008080",
        thistle: "#d8bfd8",
        tomato: "#ff6347",
        turquoise: "#40e0d0",
        violet: "#ee82ee",
        wheat: "#f5deb3",
        white: "#ffffff",
        whitesmoke: "#f5f5f5",
        yellow: "#ffff00",
        yellowgreen: "#9acd32"
    });
    Kt.forEach(function(e, t) {
        Kt.set(e, Wt(t, qt, pt));
    });
    e.functor = Qt;
    e.xhr = function(t, r, i) {
        function l() {
            var e = f.status;
            !e && f.responseText || e >= 200 && e < 300 || e === 304 ? o.load.call(s, a.call(s, f)) : o.error.call(s, f);
        }
        var s = {}, o = e.dispatch("progress", "load", "error"), u = {}, a = Gt, f = new (n.XDomainRequest && /^(http(s)?:)?\/\//.test(t) ? XDomainRequest : XMLHttpRequest);
        "onload" in f ? f.onload = f.onerror = l : f.onreadystatechange = function() {
            f.readyState > 3 && l();
        };
        f.onprogress = function(t) {
            var n = e.event;
            e.event = t;
            try {
                o.progress.call(s, f);
            } finally {
                e.event = n;
            }
        };
        s.header = function(e, t) {
            e = (e + "").toLowerCase();
            if (arguments.length < 2) return u[e];
            t == null ? delete u[e] : u[e] = t + "";
            return s;
        };
        s.mimeType = function(e) {
            if (!arguments.length) return r;
            r = e == null ? null : e + "";
            return s;
        };
        s.response = function(e) {
            a = e;
            return s;
        };
        [ "get", "post" ].forEach(function(e) {
            s[e] = function() {
                return s.send.apply(s, [ e ].concat(N(arguments)));
            };
        });
        s.send = function(e, n, i) {
            arguments.length === 2 && typeof n == "function" && (i = n, n = null);
            f.open(e, t, !0);
            r != null && !("accept" in u) && (u.accept = r + ",*/*");
            if (f.setRequestHeader) for (var o in u) f.setRequestHeader(o, u[o]);
            r != null && f.overrideMimeType && f.overrideMimeType(r);
            i != null && s.on("error", i).on("load", function(e) {
                i(null, e);
            });
            f.send(n == null ? null : n);
            return s;
        };
        s.abort = function() {
            f.abort();
            return s;
        };
        e.rebind(s, o, "on");
        arguments.length === 2 && typeof r == "function" && (i = r, r = null);
        return i == null ? s : s.get(Yt(i));
    };
    e.csv = Zt(",", "text/csv");
    e.tsv = Zt("	", "text/tab-separated-values");
    var en = 0, tn = {}, nn = null, rn, sn;
    e.timer = function(e, t, n) {
        if (arguments.length < 3) {
            if (arguments.length < 2) t = 0; else if (!isFinite(t)) return;
            n = Date.now();
        }
        var r = tn[e.id];
        if (r && r.callback === e) {
            r.then = n;
            r.delay = t;
        } else tn[e.id = ++en] = nn = {
            callback: e,
            then: n,
            delay: t,
            next: nn
        };
        if (!rn) {
            sn = clearTimeout(sn);
            rn = 1;
            an(on);
        }
    };
    e.timer.flush = function() {
        var e, t = Date.now(), n = nn;
        while (n) {
            e = t - n.then;
            n.delay || (n.flush = n.callback(e));
            n = n.next;
        }
        un();
    };
    var an = n.requestAnimationFrame || n.webkitRequestAnimationFrame || n.mozRequestAnimationFrame || n.oRequestAnimationFrame || n.msRequestAnimationFrame || function(e) {
        setTimeout(e, 17);
    }, fn = ".", ln = ",", cn = [ 3, 3 ], hn = [ "y", "z", "a", "f", "p", "n", "µ", "m", "", "k", "M", "G", "T", "P", "E", "Z", "Y" ].map(pn);
    e.formatPrefix = function(t, n) {
        var r = 0;
        if (t) {
            t < 0 && (t *= -1);
            n && (t = e.round(t, mn(t, n)));
            r = 1 + Math.floor(1e-12 + Math.log(t) / Math.LN10);
            r = Math.max(-24, Math.min(24, Math.floor((r <= 0 ? r + 1 : r - 1) / 3) * 3));
        }
        return hn[8 + r / 3];
    };
    e.round = function(e, t) {
        return t ? Math.round(e * (t = Math.pow(10, t))) / t : Math.round(e);
    };
    e.format = function(t) {
        var n = dn.exec(t), r = n[1] || " ", i = n[2] || ">", s = n[3] || "", o = n[4] || "", u = n[5], a = +n[6], f = n[7], l = n[8], c = n[9], h = 1, p = "", d = !1;
        l && (l = +l.substring(1));
        if (u || r === "0" && i === "=") {
            u = r = "0";
            i = "=";
            f && (a -= Math.floor((a - 1) / 4));
        }
        switch (c) {
          case "n":
            f = !0;
            c = "g";
            break;
          case "%":
            h = 100;
            p = "%";
            c = "f";
            break;
          case "p":
            h = 100;
            p = "%";
            c = "r";
            break;
          case "b":
          case "o":
          case "x":
          case "X":
            o && (o = "0" + c.toLowerCase());
          case "c":
          case "d":
            d = !0;
            l = 0;
            break;
          case "s":
            h = -1;
            c = "r";
        }
        o === "#" && (o = "");
        c == "r" && !l && (c = "g");
        if (l != null) if (c == "g") l = Math.max(1, Math.min(21, l)); else if (c == "e" || c == "f") l = Math.max(0, Math.min(20, l));
        c = vn.get(c) || gn;
        var v = u && f;
        return function(t) {
            if (d && t % 1) return "";
            var n = t < 0 || t === 0 && 1 / t < 0 ? (t = -t, "-") : s;
            if (h < 0) {
                var m = e.formatPrefix(t, l);
                t = m.scale(t);
                p = m.symbol;
            } else t *= h;
            t = c(t, l);
            !u && f && (t = yn(t));
            var g = o.length + t.length + (v ? 0 : n.length), y = g < a ? (new Array(g = a - g + 1)).join(r) : "";
            v && (t = yn(y + t));
            fn && t.replace(".", fn);
            n += o;
            return (i === "<" ? n + t + y : i === ">" ? y + n + t : i === "^" ? y.substring(0, g >>= 1) + n + t + y.substring(g) : n + (v ? t : y + t)) + p;
        };
    };
    var dn = /(?:([^{])?([<>=^]))?([+\- ])?(#)?(0)?(\d+)?(,)?(\.-?\d+)?([a-z%])?/i, vn = e.map({
        b: function(e) {
            return e.toString(2);
        },
        c: function(e) {
            return String.fromCharCode(e);
        },
        o: function(e) {
            return e.toString(8);
        },
        x: function(e) {
            return e.toString(16);
        },
        X: function(e) {
            return e.toString(16).toUpperCase();
        },
        g: function(e, t) {
            return e.toPrecision(t);
        },
        e: function(e, t) {
            return e.toExponential(t);
        },
        f: function(e, t) {
            return e.toFixed(t);
        },
        r: function(t, n) {
            return (t = e.round(t, mn(t, n))).toFixed(Math.max(0, Math.min(20, mn(t * (1 + 1e-15), n))));
        }
    }), yn = Gt;
    if (cn) {
        var bn = cn.length;
        yn = function(e) {
            var t = e.lastIndexOf("."), n = t >= 0 ? "." + e.substring(t + 1) : (t = e.length, ""), r = [], i = 0, s = cn[0];
            while (t > 0 && s > 0) {
                r.push(e.substring(t -= s, t + s));
                s = cn[i = (i + 1) % bn];
            }
            return r.reverse().join(ln || "") + n;
        };
    }
    e.geo = {};
    e.geo.stream = function(e, t) {
        e && En.hasOwnProperty(e.type) ? En[e.type](e, t) : wn(e, t);
    };
    var En = {
        Feature: function(e, t) {
            wn(e.geometry, t);
        },
        FeatureCollection: function(e, t) {
            var n = e.features, r = -1, i = n.length;
            while (++r < i) wn(n[r].geometry, t);
        }
    }, Sn = {
        Sphere: function(e, t) {
            t.sphere();
        },
        Point: function(e, t) {
            var n = e.coordinates;
            t.point(n[0], n[1]);
        },
        MultiPoint: function(e, t) {
            var n = e.coordinates, r = -1, i = n.length, s;
            while (++r < i) s = n[r], t.point(s[0], s[1]);
        },
        LineString: function(e, t) {
            xn(e.coordinates, t, 0);
        },
        MultiLineString: function(e, t) {
            var n = e.coordinates, r = -1, i = n.length;
            while (++r < i) xn(n[r], t, 0);
        },
        Polygon: function(e, t) {
            Tn(e.coordinates, t);
        },
        MultiPolygon: function(e, t) {
            var n = e.coordinates, r = -1, i = n.length;
            while (++r < i) Tn(n[r], t);
        },
        GeometryCollection: function(e, t) {
            var n = e.geometries, r = -1, i = n.length;
            while (++r < i) wn(n[r], t);
        }
    };
    e.geo.area = function(t) {
        Nn = 0;
        e.geo.stream(t, Ln);
        return Nn;
    };
    var Nn, Cn, kn, Ln = {
        sphere: function() {
            Nn += 4 * dt;
        },
        point: G,
        lineStart: G,
        lineEnd: G,
        polygonStart: function() {
            Cn = 1, kn = 0;
            Ln.lineStart = An;
        },
        polygonEnd: function() {
            var e = 2 * Math.atan2(kn, Cn);
            Nn += e < 0 ? 4 * dt + e : e;
            Ln.lineStart = Ln.lineEnd = Ln.point = G;
        }
    };
    e.geo.bounds = On(Gt);
    e.geo.centroid = function(t) {
        Mn = _n = Dn = Pn = Hn = 0;
        e.geo.stream(t, Bn);
        var n;
        if (_n && Math.abs(n = Math.sqrt(Dn * Dn + Pn * Pn + Hn * Hn)) > vt) return [ Math.atan2(Pn, Dn) * gt, Math.asin(Math.max(-1, Math.min(1, Hn / n))) * gt ];
    };
    var Mn, _n, Dn, Pn, Hn, Bn = {
        sphere: function() {
            if (Mn < 2) {
                Mn = 2;
                _n = Dn = Pn = Hn = 0;
            }
        },
        point: jn,
        lineStart: In,
        lineEnd: qn,
        polygonStart: function() {
            if (Mn < 2) {
                Mn = 2;
                _n = Dn = Pn = Hn = 0;
            }
            Bn.lineStart = Fn;
        },
        polygonEnd: function() {
            Bn.lineStart = In;
        }
    }, rr = Yn($n, ir, or), ar = 1e9;
    e.geo.projection = pr;
    e.geo.projectionMutator = dr;
    (e.geo.equirectangular = function() {
        return pr(mr);
    }).raw = mr.invert = mr;
    e.geo.rotation = function(e) {
        function t(t) {
            t = e(t[0] * mt, t[1] * mt);
            return t[0] *= gt, t[1] *= gt, t;
        }
        e = gr(e[0] % 360 * mt, e[1] * mt, e.length > 2 ? e[2] * mt : 0);
        t.invert = function(t) {
            t = e.invert(t[0] * mt, t[1] * mt);
            return t[0] *= gt, t[1] *= gt, t;
        };
        return t;
    };
    e.geo.circle = function() {
        function i() {
            var t = typeof e == "function" ? e.apply(this, arguments) : e, n = gr(-t[0] * mt, -t[1] * mt, 0).invert, i = [];
            r(null, null, 1, {
                point: function(e, t) {
                    i.push(e = n(e, t));
                    e[0] *= gt, e[1] *= gt;
                }
            });
            return {
                type: "Polygon",
                coordinates: [ i ]
            };
        }
        var e = [ 0, 0 ], t, n = 6, r;
        i.origin = function(t) {
            if (!arguments.length) return e;
            e = t;
            return i;
        };
        i.angle = function(e) {
            if (!arguments.length) return t;
            r = Er((t = +e) * mt, n * mt);
            return i;
        };
        i.precision = function(e) {
            if (!arguments.length) return n;
            r = Er(t * mt, (n = +e) * mt);
            return i;
        };
        return i.angle(90);
    };
    e.geo.distance = function(e, t) {
        var n = (t[0] - e[0]) * mt, r = e[1] * mt, i = t[1] * mt, s = Math.sin(n), o = Math.cos(n), u = Math.sin(r), a = Math.cos(r), f = Math.sin(i), l = Math.cos(i), c;
        return Math.atan2(Math.sqrt((c = l * s) * c + (c = a * f - u * l * o) * c), u * f + a * l * o);
    };
    e.geo.graticule = function() {
        function y() {
            return {
                type: "MultiLineString",
                coordinates: b()
            };
        }
        function b() {
            return e.range(Math.ceil(i / c) * c, r, c).map(v).concat(e.range(Math.ceil(a / h) * h, u, h).map(m)).concat(e.range(Math.ceil(n / f) * f, t, f).filter(function(e) {
                return Math.abs(e % c) > vt;
            }).map(p)).concat(e.range(Math.ceil(o / l) * l, s, l).filter(function(e) {
                return Math.abs(e % h) > vt;
            }).map(d));
        }
        var t, n, r, i, s, o, u, a, f = 10, l = f, c = 90, h = 360, p, d, v, m, g = 2.5;
        y.lines = function() {
            return b().map(function(e) {
                return {
                    type: "LineString",
                    coordinates: e
                };
            });
        };
        y.outline = function() {
            return {
                type: "Polygon",
                coordinates: [ v(i).concat(m(u).slice(1), v(r).reverse().slice(1), m(a).reverse().slice(1)) ]
            };
        };
        y.extent = function(e) {
            return arguments.length ? y.majorExtent(e).minorExtent(e) : y.minorExtent();
        };
        y.majorExtent = function(e) {
            if (!arguments.length) return [ [ i, a ], [ r, u ] ];
            i = +e[0][0], r = +e[1][0];
            a = +e[0][1], u = +e[1][1];
            i > r && (e = i, i = r, r = e);
            a > u && (e = a, a = u, u = e);
            return y.precision(g);
        };
        y.minorExtent = function(e) {
            if (!arguments.length) return [ [ n, o ], [ t, s ] ];
            n = +e[0][0], t = +e[1][0];
            o = +e[0][1], s = +e[1][1];
            n > t && (e = n, n = t, t = e);
            o > s && (e = o, o = s, s = e);
            return y.precision(g);
        };
        y.step = function(e) {
            return arguments.length ? y.majorStep(e).minorStep(e) : y.minorStep();
        };
        y.majorStep = function(e) {
            if (!arguments.length) return [ c, h ];
            c = +e[0], h = +e[1];
            return y;
        };
        y.minorStep = function(e) {
            if (!arguments.length) return [ f, l ];
            f = +e[0], l = +e[1];
            return y;
        };
        y.precision = function(e) {
            if (!arguments.length) return g;
            g = +e;
            p = xr(o, s, 90);
            d = Tr(n, t, g);
            v = xr(a, u, 90);
            m = Tr(i, r, g);
            return y;
        };
        return y.majorExtent([ [ -180, -90 + vt ], [ 180, 90 - vt ] ]).minorExtent([ [ -180, -80 - vt ], [ 180, 80 + vt ] ]);
    };
    e.geo.greatArc = function() {
        function s() {
            return {
                type: "LineString",
                coordinates: [ n || t.apply(this, arguments), i || r.apply(this, arguments) ]
            };
        }
        var t = Nr, n, r = Cr, i;
        s.distance = function() {
            return e.geo.distance(n || t.apply(this, arguments), i || r.apply(this, arguments));
        };
        s.source = function(e) {
            if (!arguments.length) return t;
            t = e, n = typeof e == "function" ? null : e;
            return s;
        };
        s.target = function(e) {
            if (!arguments.length) return r;
            r = e, i = typeof e == "function" ? null : e;
            return s;
        };
        s.precision = function() {
            return arguments.length ? s : 0;
        };
        return s;
    };
    e.geo.interpolate = function(e, t) {
        return kr(e[0] * mt, e[1] * mt, t[0] * mt, t[1] * mt);
    };
    e.geo.length = function(t) {
        Lr = 0;
        e.geo.stream(t, Ar);
        return Lr;
    };
    var Lr, Ar = {
        sphere: G,
        point: G,
        lineStart: Or,
        lineEnd: G,
        polygonStart: G,
        polygonEnd: G
    };
    (e.geo.conicEqualArea = function() {
        return Mr(_r);
    }).raw = _r;
    e.geo.albersUsa = function() {
        function a(e) {
            return f(e)(e);
        }
        function f(e) {
            var s = e[0], o = e[1];
            return o > 50 ? n : s < -140 ? r : o < 21 ? i : t;
        }
        var t = e.geo.conicEqualArea().rotate([ 98, 0 ]).center([ 0, 38 ]).parallels([ 29.5, 45.5 ]), n = e.geo.conicEqualArea().rotate([ 160, 0 ]).center([ 0, 60 ]).parallels([ 55, 65 ]), r = e.geo.conicEqualArea().rotate([ 160, 0 ]).center([ 0, 20 ]).parallels([ 8, 18 ]), i = e.geo.conicEqualArea().rotate([ 60, 0 ]).center([ 0, 10 ]).parallels([ 8, 18 ]), s, o, u;
        a.invert = function(e) {
            return s(e) || o(e) || u(e) || t.invert(e);
        };
        a.scale = function(e) {
            if (!arguments.length) return t.scale();
            t.scale(e);
            n.scale(e * .6);
            r.scale(e);
            i.scale(e * 1.5);
            return a.translate(t.translate());
        };
        a.translate = function(e) {
            if (!arguments.length) return t.translate();
            var f = t.scale(), l = e[0], c = e[1];
            t.translate(e);
            n.translate([ l - .4 * f, c + .17 * f ]);
            r.translate([ l - .19 * f, c + .2 * f ]);
            i.translate([ l + .58 * f, c + .43 * f ]);
            s = Dr(n, [ [ -180, 50 ], [ -130, 72 ] ]);
            o = Dr(r, [ [ -164, 18 ], [ -154, 24 ] ]);
            u = Dr(i, [ [ -67.5, 17.5 ], [ -65, 19 ] ]);
            return a;
        };
        return a.scale(1e3);
    };
    var Pr, Hr, Br = {
        point: G,
        lineStart: G,
        lineEnd: G,
        polygonStart: function() {
            Hr = 0;
            Br.lineStart = jr;
        },
        polygonEnd: function() {
            Br.lineStart = Br.lineEnd = Br.point = G;
            Pr += Math.abs(Hr / 2);
        }
    }, Ir = {
        point: qr,
        lineStart: Rr,
        lineEnd: Ur,
        polygonStart: function() {
            Ir.lineStart = zr;
        },
        polygonEnd: function() {
            Ir.point = qr;
            Ir.lineStart = Rr;
            Ir.lineEnd = Ur;
        }
    };
    e.geo.path = function() {
        function o(n) {
            n && e.geo.stream(n, i(s.pointRadius(typeof t == "function" ? +t.apply(this, arguments) : t)));
            return s.result();
        }
        var t = 4.5, n, r, i, s;
        o.area = function(t) {
            Pr = 0;
            e.geo.stream(t, i(Br));
            return Pr;
        };
        o.centroid = function(t) {
            Mn = Dn = Pn = Hn = 0;
            e.geo.stream(t, i(Ir));
            return Hn ? [ Dn / Hn, Pn / Hn ] : undefined;
        };
        o.bounds = function(e) {
            return On(i)(e);
        };
        o.projection = function(e) {
            if (!arguments.length) return n;
            i = (n = e) ? e.stream || Vr(e) : Gt;
            return o;
        };
        o.context = function(e) {
            if (!arguments.length) return r;
            s = (r = e) == null ? new Fr : new Wr(e);
            return o;
        };
        o.pointRadius = function(e) {
            if (!arguments.length) return t;
            t = typeof e == "function" ? e : +e;
            return o;
        };
        return o.projection(e.geo.albersUsa()).context(null);
    };
    e.geo.albers = function() {
        return e.geo.conicEqualArea().parallels([ 29.5, 45.5 ]).rotate([ 98, 0 ]).center([ 0, 38 ]).scale(1e3);
    };
    var Jr = $r(function(e) {
        return Math.sqrt(2 / (1 + e));
    }, function(e) {
        return 2 * Math.asin(e / 2);
    });
    (e.geo.azimuthalEqualArea = function() {
        return pr(Jr);
    }).raw = Jr;
    var Kr = $r(function(e) {
        var t = Math.acos(e);
        return t && t / Math.sin(t);
    }, Gt);
    (e.geo.azimuthalEquidistant = function() {
        return pr(Kr);
    }).raw = Kr;
    (e.geo.conicConformal = function() {
        return Mr(Qr);
    }).raw = Qr;
    (e.geo.conicEquidistant = function() {
        return Mr(Gr);
    }).raw = Gr;
    var Yr = $r(function(e) {
        return 1 / e;
    }, Math.atan);
    (e.geo.gnomonic = function() {
        return pr(Yr);
    }).raw = Yr;
    Zr.invert = function(e, t) {
        return [ e, 2 * Math.atan(Math.exp(t)) - dt / 2 ];
    };
    (e.geo.mercator = function() {
        return ei(Zr);
    }).raw = Zr;
    var ti = $r(function() {
        return 1;
    }, Math.asin);
    (e.geo.orthographic = function() {
        return pr(ti);
    }).raw = ti;
    var ni = $r(function(e) {
        return 1 / (1 + e);
    }, function(e) {
        return 2 * Math.atan(e);
    });
    (e.geo.stereographic = function() {
        return pr(ni);
    }).raw = ni;
    ri.invert = function(e, t) {
        return [ Math.atan2(Et(e), Math.cos(t)), wt(Math.sin(t) / St(e)) ];
    };
    (e.geo.transverseMercator = function() {
        return ei(ri);
    }).raw = ri;
    e.geom = {};
    e.svg = {};
    e.svg.line = function() {
        return ii(Gt);
    };
    var ui = e.map({
        linear: ai,
        "linear-closed": fi,
        "step-before": li,
        "step-after": ci,
        basis: gi,
        "basis-open": yi,
        "basis-closed": bi,
        bundle: wi,
        cardinal: di,
        "cardinal-open": hi,
        "cardinal-closed": pi,
        monotone: Ai
    });
    ui.forEach(function(e, t) {
        t.key = e;
        t.closed = /-closed$/.test(e);
    });
    var Si = [ 0, 2 / 3, 1 / 3, 0 ], xi = [ 0, 1 / 3, 2 / 3, 0 ], Ti = [ 0, 1 / 6, 2 / 3, 1 / 6 ];
    e.geom.hull = function(e) {
        function r(e) {
            if (e.length < 3) return [];
            var r = Qt(t), i = Qt(n), s = e.length, o, u = s - 1, a = [], f = [], l, c, h, p = 0, d, v, m, g, y, b, w, E;
            if (r === si && n === oi) o = e; else for (c = 0, o = []; c < s; ++c) o.push([ +r.call(this, l = e[c], c), +i.call(this, l, c) ]);
            for (c = 1; c < s; ++c) o[c][1] < o[p][1] ? p = c : o[c][1] == o[p][1] && (p = o[c][0] < o[p][0] ? c : p);
            for (c = 0; c < s; ++c) {
                if (c === p) continue;
                v = o[c][1] - o[p][1];
                d = o[c][0] - o[p][0];
                a.push({
                    angle: Math.atan2(v, d),
                    index: c
                });
            }
            a.sort(function(e, t) {
                return e.angle - t.angle;
            });
            w = a[0].angle;
            b = a[0].index;
            y = 0;
            for (c = 1; c < u; ++c) {
                h = a[c].index;
                if (w == a[c].angle) {
                    d = o[b][0] - o[p][0];
                    v = o[b][1] - o[p][1];
                    m = o[h][0] - o[p][0];
                    g = o[h][1] - o[p][1];
                    if (d * d + v * v >= m * m + g * g) a[c].index = -1; else {
                        a[y].index = -1;
                        w = a[c].angle;
                        y = c;
                        b = h;
                    }
                } else {
                    w = a[c].angle;
                    y = c;
                    b = h;
                }
            }
            f.push(p);
            for (c = 0, h = 0; c < 2; ++h) if (a[h].index !== -1) {
                f.push(a[h].index);
                c++;
            }
            E = f.length;
            for (; h < u; ++h) {
                if (a[h].index === -1) continue;
                while (!Oi(f[E - 2], f[E - 1], a[h].index, o)) --E;
                f[E++] = a[h].index;
            }
            var S = [];
            for (c = 0; c < E; ++c) S.push(e[f[c]]);
            return S;
        }
        var t = si, n = oi;
        if (arguments.length) return r(e);
        r.x = function(e) {
            return arguments.length ? (t = e, r) : t;
        };
        r.y = function(e) {
            return arguments.length ? (n = e, r) : n;
        };
        return r;
    };
    e.geom.polygon = function(e) {
        e.area = function() {
            var t = 0, n = e.length, r = e[n - 1][1] * e[0][0] - e[n - 1][0] * e[0][1];
            while (++t < n) r += e[t - 1][1] * e[t][0] - e[t - 1][0] * e[t][1];
            return r * .5;
        };
        e.centroid = function(t) {
            var n = -1, r = e.length, i = 0, s = 0, o, u = e[r - 1], a;
            arguments.length || (t = -1 / (6 * e.area()));
            while (++n < r) {
                o = u;
                u = e[n];
                a = o[0] * u[1] - u[0] * o[1];
                i += (o[0] + u[0]) * a;
                s += (o[1] + u[1]) * a;
            }
            return [ i * t, s * t ];
        };
        e.clip = function(t) {
            var n, r = -1, i = e.length, s, o, u = e[i - 1], a, f, l;
            while (++r < i) {
                n = t.slice();
                t.length = 0;
                a = e[r];
                f = n[(o = n.length) - 1];
                s = -1;
                while (++s < o) {
                    l = n[s];
                    if (Mi(l, u, a)) {
                        Mi(f, u, a) || t.push(_i(f, l, u, a));
                        t.push(l);
                    } else Mi(f, u, a) && t.push(_i(f, l, u, a));
                    f = l;
                }
                u = a;
            }
            return t;
        };
        return e;
    };
    e.geom.delaunay = function(e) {
        var t = e.map(function() {
            return [];
        }), n = [];
        Pi(e, function(n) {
            t[n.region.l.index].push(e[n.region.r.index]);
        });
        t.forEach(function(t, r) {
            var i = e[r], s = i[0], o = i[1];
            t.forEach(function(e) {
                e.angle = Math.atan2(e[0] - s, e[1] - o);
            });
            t.sort(function(e, t) {
                return e.angle - t.angle;
            });
            for (var u = 0, a = t.length - 1; u < a; u++) n.push([ i, t[u], t[u + 1] ]);
        });
        return n;
    };
    e.geom.voronoi = function(t) {
        function o(t) {
            var n, o = t.map(function() {
                return [];
            }), u = Qt(r), a = Qt(i), f, l, c = t.length, h = 1e6;
            if (u === si && a === oi) n = t; else for (n = [], l = 0; l < c; ++l) n.push([ +u.call(this, f = t[l], l), +a.call(this, f, l) ]);
            Pi(n, function(e) {
                var t, n, r, i, s, u;
                if (e.a === 1 && e.b >= 0) {
                    t = e.ep.r;
                    n = e.ep.l;
                } else {
                    t = e.ep.l;
                    n = e.ep.r;
                }
                if (e.a === 1) {
                    s = t ? t.y : -h;
                    r = e.c - e.b * s;
                    u = n ? n.y : h;
                    i = e.c - e.b * u;
                } else {
                    r = t ? t.x : -h;
                    s = e.c - e.a * r;
                    i = n ? n.x : h;
                    u = e.c - e.a * i;
                }
                var a = [ r, s ], f = [ i, u ];
                o[e.region.l.index].push(a, f);
                o[e.region.r.index].push(a, f);
            });
            o = o.map(function(t, r) {
                var i = n[r][0], s = n[r][1], o = t.map(function(e) {
                    return Math.atan2(e[0] - i, e[1] - s);
                }), u = e.range(t.length).sort(function(e, t) {
                    return o[e] - o[t];
                });
                return u.filter(function(e, t) {
                    return !t || o[e] - o[u[t - 1]] > vt;
                }).map(function(e) {
                    return t[e];
                });
            });
            o.forEach(function(e, t) {
                var r = e.length;
                if (!r) return e.push([ -h, -h ], [ -h, h ], [ h, h ], [ h, -h ]);
                if (r > 2) return;
                var i = n[t], s = e[0], o = e[1], u = i[0], a = i[1], f = s[0], l = s[1], c = o[0], p = o[1], d = Math.abs(c - f), v = p - l;
                if (Math.abs(v) < vt) {
                    var m = a < l ? -h : h;
                    e.push([ -h, m ], [ h, m ]);
                } else if (d < vt) {
                    var g = u < f ? -h : h;
                    e.push([ g, -h ], [ g, h ]);
                } else {
                    var m = (c - f) * (l - a) < (f - u) * (p - l) ? h : -h, y = Math.abs(v) - d;
                    if (Math.abs(y) < vt) e.push([ v < 0 ? m : -m, m ]); else {
                        y > 0 && (m *= -1);
                        e.push([ -h, m ], [ h, m ]);
                    }
                }
            });
            if (s) for (l = 0; l < c; ++l) s(o[l]);
            for (l = 0; l < c; ++l) o[l].point = t[l];
            return o;
        }
        var n = null, r = si, i = oi, s;
        if (arguments.length) return o(t);
        o.x = function(e) {
            return arguments.length ? (r = e, o) : r;
        };
        o.y = function(e) {
            return arguments.length ? (i = e, o) : i;
        };
        o.size = function(t) {
            if (!arguments.length) return n;
            if (t == null) s = null; else {
                n = [ +t[0], +t[1] ];
                s = e.geom.polygon([ [ 0, 0 ], [ 0, n[1] ], n, [ n[0], 0 ] ]).clip;
            }
            return o;
        };
        o.links = function(e) {
            var t, n = e.map(function() {
                return [];
            }), s = [], o = Qt(r), u = Qt(i), a, f, l = e.length;
            if (o === si && u === oi) t = e; else for (f = 0; f < l; ++f) t.push([ +o.call(this, a = e[f], f), +u.call(this, a, f) ]);
            Pi(t, function(t) {
                var r = t.region.l.index, i = t.region.r.index;
                if (n[r][i]) return;
                n[r][i] = n[i][r] = !0;
                s.push({
                    source: e[r],
                    target: e[i]
                });
            });
            return s;
        };
        o.triangles = function(t) {
            if (r === si && i === oi) return e.geom.delaunay(t);
            var n, s, o = Qt(r), u = Qt(i), a, f, l;
            for (f = 0, n = [], l = t.length; f < l; ++f) {
                s = [ +o.call(this, a = t[f], f), +u.call(this, a, f) ];
                s.data = a;
                n.push(s);
            }
            return e.geom.delaunay(n).map(function(e) {
                return e.map(function(e) {
                    return e.data;
                });
            });
        };
        return o;
    };
    var Di = {
        l: "r",
        r: "l"
    };
    e.geom.quadtree = function(e, t, n, r, i) {
        function a(e) {
            function x(e, t, n, r, i, s, o, u) {
                if (isNaN(n) || isNaN(r)) return;
                if (e.leaf) {
                    var a = e.x, f = e.y;
                    if (a != null) if (Math.abs(a - n) + Math.abs(f - r) < .01) T(e, t, n, r, i, s, o, u); else {
                        var l = e.point;
                        e.x = e.y = e.point = null;
                        T(e, l, a, f, i, s, o, u);
                        T(e, t, n, r, i, s, o, u);
                    } else e.x = n, e.y = r, e.point = t;
                } else T(e, t, n, r, i, s, o, u);
            }
            function T(e, t, n, r, i, s, o, u) {
                var a = (i + o) * .5, f = (s + u) * .5, l = n >= a, c = r >= f, h = (c << 1) + l;
                e.leaf = !1;
                e = e.nodes[h] || (e.nodes[h] = ji());
                l ? i = a : o = a;
                c ? s = f : u = f;
                x(e, t, n, r, i, s, o, u);
            }
            var a, f = Qt(s), l = Qt(o), c, h, p, d, v, m, g, y;
            if (t != null) v = t, m = n, g = r, y = i; else {
                g = y = -(v = m = Infinity);
                c = [], h = [];
                d = e.length;
                if (u) for (p = 0; p < d; ++p) {
                    a = e[p];
                    a.x < v && (v = a.x);
                    a.y < m && (m = a.y);
                    a.x > g && (g = a.x);
                    a.y > y && (y = a.y);
                    c.push(a.x);
                    h.push(a.y);
                } else for (p = 0; p < d; ++p) {
                    var b = +f(a = e[p], p), w = +l(a, p);
                    b < v && (v = b);
                    w < m && (m = w);
                    b > g && (g = b);
                    w > y && (y = w);
                    c.push(b);
                    h.push(w);
                }
            }
            var E = g - v, S = y - m;
            E > S ? y = m + E : g = v + S;
            var N = ji();
            N.add = function(e) {
                x(N, e, +f(e, ++p), +l(e, p), v, m, g, y);
            };
            N.visit = function(e) {
                Fi(e, N, v, m, g, y);
            };
            p = -1;
            if (t == null) {
                while (++p < d) x(N, e[p], c[p], h[p], v, m, g, y);
                --p;
            } else e.forEach(N.add);
            c = h = e = a = null;
            return N;
        }
        var s = si, o = oi, u;
        if (u = arguments.length) {
            s = Hi;
            o = Bi;
            if (u === 3) {
                i = n;
                r = t;
                n = t = 0;
            }
            return a(e);
        }
        a.x = function(e) {
            return arguments.length ? (s = e, a) : s;
        };
        a.y = function(e) {
            return arguments.length ? (o = e, a) : o;
        };
        a.size = function(e) {
            if (!arguments.length) return t == null ? null : [ r, i ];
            if (e == null) t = n = r = i = null; else {
                t = n = 0;
                r = +e[0], i = +e[1];
            }
            return a;
        };
        return a;
    };
    e.interpolateRgb = Ii;
    e.transform = function(n) {
        var r = t.createElementNS(e.ns.prefix.svg, "g");
        return (e.transform = function(e) {
            r.setAttribute("transform", e);
            var t = r.transform.baseVal.consolidate();
            return new qi(t ? t.matrix : Wi);
        })(n);
    };
    qi.prototype.toString = function() {
        return "translate(" + this.translate + ")rotate(" + this.rotate + ")skewX(" + this.skew + ")scale(" + this.scale + ")";
    };
    var Wi = {
        a: 1,
        b: 0,
        c: 0,
        d: 1,
        e: 0,
        f: 0
    };
    e.interpolateNumber = Xi;
    e.interpolateTransform = Vi;
    e.interpolateObject = $i;
    e.interpolateString = Ji;
    var Ki = /[-+]?(?:\d+\.?\d*|\.?\d+)(?:[eE][-+]?\d+)?/g;
    e.interpolate = Qi;
    e.interpolators = [ function(e, t) {
        var n = typeof t;
        return (n === "string" || n !== typeof e ? Kt.has(t) || /^(#|rgb\(|hsl\()/.test(t) ? Ii : Ji : t instanceof ft ? Ii : n === "object" ? Array.isArray(t) ? Yi : $i : Xi)(e, t);
    } ];
    e.interpolateArray = Yi;
    var Zi = function() {
        return Gt;
    }, es = e.map({
        linear: Zi,
        poly: as,
        quad: function() {
            return ss;
        },
        cubic: function() {
            return os;
        },
        sin: function() {
            return fs;
        },
        exp: function() {
            return ls;
        },
        circle: function() {
            return cs;
        },
        elastic: hs,
        back: ps,
        bounce: function() {
            return ds;
        }
    }), ts = e.map({
        "in": Gt,
        out: rs,
        "in-out": is,
        "out-in": function(e) {
            return is(rs(e));
        }
    });
    e.ease = function(e) {
        var t = e.indexOf("-"), n = t >= 0 ? e.substring(0, t) : e, r = t >= 0 ? e.substring(t + 1) : "in";
        n = es.get(n) || Zi;
        r = ts.get(r) || Gt;
        return ns(r(n.apply(null, Array.prototype.slice.call(arguments, 1))));
    };
    e.interpolateHcl = vs;
    e.interpolateHsl = ms;
    e.interpolateLab = gs;
    e.interpolateRound = ys;
    e.layout = {};
    e.layout.bundle = function() {
        return function(e) {
            var t = [], n = -1, r = e.length;
            while (++n < r) t.push(Es(e[n]));
            return t;
        };
    };
    e.layout.chord = function() {
        function l() {
            var t = {}, l = [], h = e.range(s), p = [], d, v, m, g, y;
            n = [];
            r = [];
            d = 0, g = -1;
            while (++g < s) {
                v = 0, y = -1;
                while (++y < s) v += i[g][y];
                l.push(v);
                p.push(e.range(s));
                d += v;
            }
            u && h.sort(function(e, t) {
                return u(l[e], l[t]);
            });
            a && p.forEach(function(e, t) {
                e.sort(function(e, n) {
                    return a(i[t][e], i[t][n]);
                });
            });
            d = (2 * dt - o * s) / d;
            v = 0, g = -1;
            while (++g < s) {
                m = v, y = -1;
                while (++y < s) {
                    var b = h[g], w = p[b][y], E = i[b][w], S = v, x = v += E * d;
                    t[b + "-" + w] = {
                        index: b,
                        subindex: w,
                        startAngle: S,
                        endAngle: x,
                        value: E
                    };
                }
                r[b] = {
                    index: b,
                    startAngle: m,
                    endAngle: v,
                    value: (v - m) / d
                };
                v += o;
            }
            g = -1;
            while (++g < s) {
                y = g - 1;
                while (++y < s) {
                    var T = t[g + "-" + y], N = t[y + "-" + g];
                    (T.value || N.value) && n.push(T.value < N.value ? {
                        source: N,
                        target: T
                    } : {
                        source: T,
                        target: N
                    });
                }
            }
            f && c();
        }
        function c() {
            n.sort(function(e, t) {
                return f((e.source.value + e.target.value) / 2, (t.source.value + t.target.value) / 2);
            });
        }
        var t = {}, n, r, i, s, o = 0, u, a, f;
        t.matrix = function(e) {
            if (!arguments.length) return i;
            s = (i = e) && i.length;
            n = r = null;
            return t;
        };
        t.padding = function(e) {
            if (!arguments.length) return o;
            o = e;
            n = r = null;
            return t;
        };
        t.sortGroups = function(e) {
            if (!arguments.length) return u;
            u = e;
            n = r = null;
            return t;
        };
        t.sortSubgroups = function(e) {
            if (!arguments.length) return a;
            a = e;
            n = null;
            return t;
        };
        t.sortChords = function(e) {
            if (!arguments.length) return f;
            f = e;
            n && c();
            return t;
        };
        t.chords = function() {
            n || l();
            return n;
        };
        t.groups = function() {
            r || l();
            return r;
        };
        return t;
    };
    e.layout.force = function() {
        function g(e) {
            return function(t, n, r, i) {
                if (t.point !== e) {
                    var s = t.cx - e.x, o = t.cy - e.y, u = 1 / Math.sqrt(s * s + o * o);
                    if ((i - n) * u < c) {
                        var a = t.charge * u * u;
                        e.px -= s * a;
                        e.py -= o * a;
                        return !0;
                    }
                    if (t.point && isFinite(u)) {
                        var a = t.pointCharge * u * u;
                        e.px -= s * a;
                        e.py -= o * a;
                    }
                }
                return !t.charge;
            };
        }
        function y(n) {
            n.px = e.event.x, n.py = e.event.y;
            t.resume();
        }
        var t = {}, n = e.dispatch("start", "tick", "end"), r = [ 1, 1 ], i, s, o = .9, u = As, a = Os, f = -30, l = .1, c = .8, h = [], p = [], d, v, m;
        t.tick = function() {
            if ((s *= .99) < .005) {
                n.end({
                    type: "end",
                    alpha: s = 0
                });
                return !0;
            }
            var t = h.length, i = p.length, u, a, c, y, b, w, E, S, x;
            for (a = 0; a < i; ++a) {
                c = p[a];
                y = c.source;
                b = c.target;
                S = b.x - y.x;
                x = b.y - y.y;
                if (w = S * S + x * x) {
                    w = s * v[a] * ((w = Math.sqrt(w)) - d[a]) / w;
                    S *= w;
                    x *= w;
                    b.x -= S * (E = y.weight / (b.weight + y.weight));
                    b.y -= x * E;
                    y.x += S * (E = 1 - E);
                    y.y += x * E;
                }
            }
            if (E = s * l) {
                S = r[0] / 2;
                x = r[1] / 2;
                a = -1;
                if (E) while (++a < t) {
                    c = h[a];
                    c.x += (S - c.x) * E;
                    c.y += (x - c.y) * E;
                }
            }
            if (f) {
                Ls(u = e.geom.quadtree(h), s, m);
                a = -1;
                while (++a < t) (c = h[a]).fixed || u.visit(g(c));
            }
            a = -1;
            while (++a < t) {
                c = h[a];
                if (c.fixed) {
                    c.x = c.px;
                    c.y = c.py;
                } else {
                    c.x -= (c.px - (c.px = c.x)) * o;
                    c.y -= (c.py - (c.py = c.y)) * o;
                }
            }
            n.tick({
                type: "tick",
                alpha: s
            });
        };
        t.nodes = function(e) {
            if (!arguments.length) return h;
            h = e;
            return t;
        };
        t.links = function(e) {
            if (!arguments.length) return p;
            p = e;
            return t;
        };
        t.size = function(e) {
            if (!arguments.length) return r;
            r = e;
            return t;
        };
        t.linkDistance = function(e) {
            if (!arguments.length) return u;
            u = typeof e == "function" ? e : +e;
            return t;
        };
        t.distance = t.linkDistance;
        t.linkStrength = function(e) {
            if (!arguments.length) return a;
            a = typeof e == "function" ? e : +e;
            return t;
        };
        t.friction = function(e) {
            if (!arguments.length) return o;
            o = +e;
            return t;
        };
        t.charge = function(e) {
            if (!arguments.length) return f;
            f = typeof e == "function" ? e : +e;
            return t;
        };
        t.gravity = function(e) {
            if (!arguments.length) return l;
            l = +e;
            return t;
        };
        t.theta = function(e) {
            if (!arguments.length) return c;
            c = +e;
            return t;
        };
        t.alpha = function(r) {
            if (!arguments.length) return s;
            r = +r;
            if (s) r > 0 ? s = r : s = 0; else if (r > 0) {
                n.start({
                    type: "start",
                    alpha: s = r
                });
                e.timer(t.tick);
            }
            return t;
        };
        t.start = function() {
            function y(t, n) {
                var r = b(e), i = -1, s = r.length, o;
                while (++i < s) if (!isNaN(o = r[i][t])) return o;
                return Math.random() * n;
            }
            function b() {
                if (!c) {
                    c = [];
                    for (n = 0; n < i; ++n) c[n] = [];
                    for (n = 0; n < s; ++n) {
                        var t = p[n];
                        c[t.source.index].push(t.target);
                        c[t.target.index].push(t.source);
                    }
                }
                return c[e];
            }
            var e, n, i = h.length, s = p.length, o = r[0], l = r[1], c, g;
            for (e = 0; e < i; ++e) {
                (g = h[e]).index = e;
                g.weight = 0;
            }
            for (e = 0; e < s; ++e) {
                g = p[e];
                typeof g.source == "number" && (g.source = h[g.source]);
                typeof g.target == "number" && (g.target = h[g.target]);
                ++g.source.weight;
                ++g.target.weight;
            }
            for (e = 0; e < i; ++e) {
                g = h[e];
                isNaN(g.x) && (g.x = y("x", o));
                isNaN(g.y) && (g.y = y("y", l));
                isNaN(g.px) && (g.px = g.x);
                isNaN(g.py) && (g.py = g.y);
            }
            d = [];
            if (typeof u == "function") for (e = 0; e < s; ++e) d[e] = +u.call(this, p[e], e); else for (e = 0; e < s; ++e) d[e] = u;
            v = [];
            if (typeof a == "function") for (e = 0; e < s; ++e) v[e] = +a.call(this, p[e], e); else for (e = 0; e < s; ++e) v[e] = a;
            m = [];
            if (typeof f == "function") for (e = 0; e < i; ++e) m[e] = +f.call(this, h[e], e); else for (e = 0; e < i; ++e) m[e] = f;
            return t.resume();
        };
        t.resume = function() {
            return t.alpha(.1);
        };
        t.stop = function() {
            return t.alpha(0);
        };
        t.drag = function() {
            i || (i = e.behavior.drag().origin(Gt).on("dragstart.force", Ts).on("drag.force", y).on("dragend.force", Ns));
            if (!arguments.length) return i;
            this.on("mouseover.force", Cs).on("mouseout.force", ks).call(i);
        };
        return e.rebind(t, n, "on");
    };
    var As = 20, Os = 1;
    e.layout.hierarchy = function() {
        function r(i, o, u) {
            var a = t.call(s, i, o);
            i.depth = o;
            u.push(i);
            if (a && (l = a.length)) {
                var f = -1, l, c = i.children = [], h = 0, p = o + 1, d;
                while (++f < l) {
                    d = r(a[f], p, u);
                    d.parent = i;
                    c.push(d);
                    h += d.value;
                }
                e && c.sort(e);
                n && (i.value = h);
            } else n && (i.value = +n.call(s, i, o) || 0);
            return i;
        }
        function i(e, t) {
            var r = e.children, o = 0;
            if (r && (a = r.length)) {
                var u = -1, a, f = t + 1;
                while (++u < a) o += i(r[u], f);
            } else n && (o = +n.call(s, e, t) || 0);
            n && (e.value = o);
            return o;
        }
        function s(e) {
            var t = [];
            r(e, 0, t);
            return t;
        }
        var e = Ps, t = _s, n = Ds;
        s.sort = function(t) {
            if (!arguments.length) return e;
            e = t;
            return s;
        };
        s.children = function(e) {
            if (!arguments.length) return t;
            t = e;
            return s;
        };
        s.value = function(e) {
            if (!arguments.length) return n;
            n = e;
            return s;
        };
        s.revalue = function(e) {
            i(e, 0);
            return e;
        };
        return s;
    };
    e.layout.partition = function() {
        function r(e, t, n, i) {
            var s = e.children;
            e.x = t;
            e.y = e.depth * i;
            e.dx = n;
            e.dy = i;
            if (s && (u = s.length)) {
                var o = -1, u, a, f;
                n = e.value ? n / e.value : 0;
                while (++o < u) {
                    r(a = s[o], t, f = a.value * n, i);
                    t += f;
                }
            }
        }
        function i(e) {
            var t = e.children, n = 0;
            if (t && (s = t.length)) {
                var r = -1, s;
                while (++r < s) n = Math.max(n, i(t[r]));
            }
            return 1 + n;
        }
        function s(e, s) {
            var o = t.call(this, e, s);
            r(o[0], 0, n[0], n[1] / i(o[0]));
            return o;
        }
        var t = e.layout.hierarchy(), n = [ 1, 1 ];
        s.size = function(e) {
            if (!arguments.length) return n;
            n = e;
            return s;
        };
        return Ms(s, t);
    };
    e.layout.pie = function() {
        function s(o) {
            var u = o.map(function(e, n) {
                return +t.call(s, e, n);
            }), a = +(typeof r == "function" ? r.apply(this, arguments) : r), f = ((typeof i == "function" ? i.apply(this, arguments) : i) - a) / e.sum(u), l = e.range(o.length);
            n != null && l.sort(n === Bs ? function(e, t) {
                return u[t] - u[e];
            } : function(e, t) {
                return n(o[e], o[t]);
            });
            var c = [];
            l.forEach(function(e) {
                var t;
                c[e] = {
                    data: o[e],
                    value: t = u[e],
                    startAngle: a,
                    endAngle: a += t * f
                };
            });
            return c;
        }
        var t = Number, n = Bs, r = 0, i = 2 * dt;
        s.value = function(e) {
            if (!arguments.length) return t;
            t = e;
            return s;
        };
        s.sort = function(e) {
            if (!arguments.length) return n;
            n = e;
            return s;
        };
        s.startAngle = function(e) {
            if (!arguments.length) return r;
            r = e;
            return s;
        };
        s.endAngle = function(e) {
            if (!arguments.length) return i;
            i = e;
            return s;
        };
        return s;
    };
    var Bs = {};
    e.layout.stack = function() {
        function u(a, f) {
            var l = a.map(function(e, n) {
                return t.call(u, e, n);
            }), c = l.map(function(e) {
                return e.map(function(e, t) {
                    return [ s.call(u, e, t), o.call(u, e, t) ];
                });
            }), h = n.call(u, c, f);
            l = e.permute(l, h);
            c = e.permute(c, h);
            var p = r.call(u, c, f), d = l.length, v = l[0].length, m, g, y;
            for (g = 0; g < v; ++g) {
                i.call(u, l[0][g], y = p[g], c[0][g][1]);
                for (m = 1; m < d; ++m) i.call(u, l[m][g], y += c[m - 1][g][1], c[m][g][1]);
            }
            return a;
        }
        var t = Gt, n = Us, r = zs, i = Is, s = js, o = Fs;
        u.values = function(e) {
            if (!arguments.length) return t;
            t = e;
            return u;
        };
        u.order = function(e) {
            if (!arguments.length) return n;
            n = typeof e == "function" ? e : qs.get(e) || Us;
            return u;
        };
        u.offset = function(e) {
            if (!arguments.length) return r;
            r = typeof e == "function" ? e : Rs.get(e) || zs;
            return u;
        };
        u.x = function(e) {
            if (!arguments.length) return s;
            s = e;
            return u;
        };
        u.y = function(e) {
            if (!arguments.length) return o;
            o = e;
            return u;
        };
        u.out = function(e) {
            if (!arguments.length) return i;
            i = e;
            return u;
        };
        return u;
    };
    var qs = e.map({
        "inside-out": function(t) {
            var n = t.length, r, i, s = t.map(Ws), o = t.map(Xs), u = e.range(n).sort(function(e, t) {
                return s[e] - s[t];
            }), a = 0, f = 0, l = [], c = [];
            for (r = 0; r < n; ++r) {
                i = u[r];
                if (a < f) {
                    a += o[i];
                    l.push(i);
                } else {
                    f += o[i];
                    c.push(i);
                }
            }
            return c.reverse().concat(l);
        },
        reverse: function(t) {
            return e.range(t.length).reverse();
        },
        "default": Us
    }), Rs = e.map({
        silhouette: function(e) {
            var t = e.length, n = e[0].length, r = [], i = 0, s, o, u, a = [];
            for (o = 0; o < n; ++o) {
                for (s = 0, u = 0; s < t; s++) u += e[s][o][1];
                u > i && (i = u);
                r.push(u);
            }
            for (o = 0; o < n; ++o) a[o] = (i - r[o]) / 2;
            return a;
        },
        wiggle: function(e) {
            var t = e.length, n = e[0], r = n.length, i, s, o, u, a, f, l, c, h, p = [];
            p[0] = c = h = 0;
            for (s = 1; s < r; ++s) {
                for (i = 0, u = 0; i < t; ++i) u += e[i][s][1];
                for (i = 0, a = 0, l = n[s][0] - n[s - 1][0]; i < t; ++i) {
                    for (o = 0, f = (e[i][s][1] - e[i][s - 1][1]) / (2 * l); o < i; ++o) f += (e[o][s][1] - e[o][s - 1][1]) / l;
                    a += f * e[i][s][1];
                }
                p[s] = c -= u ? a / u * l : 0;
                c < h && (h = c);
            }
            for (s = 0; s < r; ++s) p[s] -= h;
            return p;
        },
        expand: function(e) {
            var t = e.length, n = e[0].length, r = 1 / t, i, s, o, u = [];
            for (s = 0; s < n; ++s) {
                for (i = 0, o = 0; i < t; i++) o += e[i][s][1];
                if (o) for (i = 0; i < t; i++) e[i][s][1] /= o; else for (i = 0; i < t; i++) e[i][s][1] = r;
            }
            for (s = 0; s < n; ++s) u[s] = 0;
            return u;
        },
        zero: zs
    });
    e.layout.histogram = function() {
        function s(s, o) {
            var u = [], a = s.map(n, this), f = r.call(this, a, o), l = i.call(this, f, a, o), c, o = -1, h = a.length, p = l.length - 1, d = t ? 1 : 1 / h, v;
            while (++o < p) {
                c = u[o] = [];
                c.dx = l[o + 1] - (c.x = l[o]);
                c.y = 0;
            }
            if (p > 0) {
                o = -1;
                while (++o < h) {
                    v = a[o];
                    if (v >= f[0] && v <= f[1]) {
                        c = u[e.bisect(l, v, 1, p) - 1];
                        c.y += d;
                        c.push(s[o]);
                    }
                }
            }
            return u;
        }
        var t = !0, n = Number, r = Ks, i = $s;
        s.value = function(e) {
            if (!arguments.length) return n;
            n = e;
            return s;
        };
        s.range = function(e) {
            if (!arguments.length) return r;
            r = Qt(e);
            return s;
        };
        s.bins = function(e) {
            if (!arguments.length) return i;
            i = typeof e == "number" ? function(t) {
                return Js(t, e);
            } : Qt(e);
            return s;
        };
        s.frequency = function(e) {
            if (!arguments.length) return t;
            t = !!e;
            return s;
        };
        return s;
    };
    e.layout.tree = function() {
        function i(e, i) {
            function u(e, t) {
                var r = e.children, i = e._tree;
                if (r && (s = r.length)) {
                    var s, o = r[0], a, l = o, c, h = -1;
                    while (++h < s) {
                        c = r[h];
                        u(c, a);
                        l = f(c, a, l);
                        a = c;
                    }
                    io(e);
                    var p = .5 * (o._tree.prelim + c._tree.prelim);
                    if (t) {
                        i.prelim = t._tree.prelim + n(e, t);
                        i.mod = i.prelim - p;
                    } else i.prelim = p;
                } else t && (i.prelim = t._tree.prelim + n(e, t));
            }
            function a(e, t) {
                e.x = e._tree.prelim + t;
                var n = e.children;
                if (n && (i = n.length)) {
                    var r = -1, i;
                    t += e._tree.mod;
                    while (++r < i) a(n[r], t);
                }
            }
            function f(e, t, r) {
                if (t) {
                    var i = e, s = e, o = t, u = e.parent.children[0], a = i._tree.mod, f = s._tree.mod, l = o._tree.mod, c = u._tree.mod, h;
                    while (o = Ys(o), i = Gs(i), o && i) {
                        u = Gs(u);
                        s = Ys(s);
                        s._tree.ancestor = e;
                        h = o._tree.prelim + l - i._tree.prelim - a + n(o, i);
                        if (h > 0) {
                            so(oo(o, e, r), e, h);
                            a += h;
                            f += h;
                        }
                        l += o._tree.mod;
                        a += i._tree.mod;
                        c += u._tree.mod;
                        f += s._tree.mod;
                    }
                    if (o && !Ys(s)) {
                        s._tree.thread = o;
                        s._tree.mod += l - f;
                    }
                    if (i && !Gs(u)) {
                        u._tree.thread = i;
                        u._tree.mod += a - c;
                        r = e;
                    }
                }
                return r;
            }
            var s = t.call(this, e, i), o = s[0];
            ro(o, function(e, t) {
                e._tree = {
                    ancestor: e,
                    prelim: 0,
                    mod: 0,
                    change: 0,
                    shift: 0,
                    number: t ? t._tree.number + 1 : 0
                };
            });
            u(o);
            a(o, -o._tree.prelim);
            var l = Zs(o, to), c = Zs(o, eo), h = Zs(o, no), p = l.x - n(l, c) / 2, d = c.x + n(c, l) / 2, v = h.depth || 1;
            ro(o, function(e) {
                e.x = (e.x - p) / (d - p) * r[0];
                e.y = e.depth / v * r[1];
                delete e._tree;
            });
            return s;
        }
        var t = e.layout.hierarchy().sort(null).value(null), n = Qs, r = [ 1, 1 ];
        i.separation = function(e) {
            if (!arguments.length) return n;
            n = e;
            return i;
        };
        i.size = function(e) {
            if (!arguments.length) return r;
            r = e;
            return i;
        };
        return Ms(i, t);
    };
    e.layout.pack = function() {
        function i(e, i) {
            var s = t.call(this, e, i), o = s[0];
            o.x = 0;
            o.y = 0;
            ro(o, function(e) {
                e.r = Math.sqrt(e.value);
            });
            ro(o, co);
            var u = r[0], a = r[1], f = Math.max(2 * o.r / u, 2 * o.r / a);
            if (n > 0) {
                var l = n * f / 2;
                ro(o, function(e) {
                    e.r += l;
                });
                ro(o, co);
                ro(o, function(e) {
                    e.r -= l;
                });
                f = Math.max(2 * o.r / u, 2 * o.r / a);
            }
            vo(o, u / 2, a / 2, 1 / f);
            return s;
        }
        var t = e.layout.hierarchy().sort(uo), n = 0, r = [ 1, 1 ];
        i.size = function(e) {
            if (!arguments.length) return r;
            r = e;
            return i;
        };
        i.padding = function(e) {
            if (!arguments.length) return n;
            n = +e;
            return i;
        };
        return Ms(i, t);
    };
    e.layout.cluster = function() {
        function i(e, i) {
            var s = t.call(this, e, i), o = s[0], u, a = 0;
            ro(o, function(e) {
                var t = e.children;
                if (t && t.length) {
                    e.x = yo(t);
                    e.y = go(t);
                } else {
                    e.x = u ? a += n(e, u) : 0;
                    e.y = 0;
                    u = e;
                }
            });
            var f = bo(o), l = wo(o), c = f.x - n(f, l) / 2, h = l.x + n(l, f) / 2;
            ro(o, function(e) {
                e.x = (e.x - c) / (h - c) * r[0];
                e.y = (1 - (o.y ? e.y / o.y : 1)) * r[1];
            });
            return s;
        }
        var t = e.layout.hierarchy().sort(null).value(null), n = Qs, r = [ 1, 1 ];
        i.separation = function(e) {
            if (!arguments.length) return n;
            n = e;
            return i;
        };
        i.size = function(e) {
            if (!arguments.length) return r;
            r = e;
            return i;
        };
        return Ms(i, t);
    };
    e.layout.treemap = function() {
        function l(e, t) {
            var n = -1, r = e.length, i, s;
            while (++n < r) {
                s = (i = e[n]).value * (t < 0 ? 0 : t);
                i.area = isNaN(s) || s <= 0 ? 0 : s;
            }
        }
        function c(e) {
            var t = e.children;
            if (t && t.length) {
                var n = s(e), r = [], i = t.slice(), o, u = Infinity, f, h = a === "slice" ? n.dx : a === "dice" ? n.dy : a === "slice-dice" ? e.depth & 1 ? n.dy : n.dx : Math.min(n.dx, n.dy), v;
                l(i, n.dx * n.dy / e.value);
                r.area = 0;
                while ((v = i.length) > 0) {
                    r.push(o = i[v - 1]);
                    r.area += o.area;
                    if (a !== "squarify" || (f = p(r, h)) <= u) {
                        i.pop();
                        u = f;
                    } else {
                        r.area -= r.pop().area;
                        d(r, h, n, !1);
                        h = Math.min(n.dx, n.dy);
                        r.length = r.area = 0;
                        u = Infinity;
                    }
                }
                if (r.length) {
                    d(r, h, n, !0);
                    r.length = r.area = 0;
                }
                t.forEach(c);
            }
        }
        function h(e) {
            var t = e.children;
            if (t && t.length) {
                var n = s(e), r = t.slice(), i, o = [];
                l(r, n.dx * n.dy / e.value);
                o.area = 0;
                while (i = r.pop()) {
                    o.push(i);
                    o.area += i.area;
                    if (i.z != null) {
                        d(o, i.z ? n.dx : n.dy, n, !r.length);
                        o.length = o.area = 0;
                    }
                }
                t.forEach(h);
            }
        }
        function p(e, t) {
            var n = e.area, r, i = 0, s = Infinity, o = -1, u = e.length;
            while (++o < u) {
                if (!(r = e[o].area)) continue;
                r < s && (s = r);
                r > i && (i = r);
            }
            n *= n;
            t *= t;
            return n ? Math.max(t * i * f / n, n / (t * s * f)) : Infinity;
        }
        function d(e, t, r, i) {
            var s = -1, o = e.length, u = r.x, a = r.y, f = t ? n(e.area / t) : 0, l;
            if (t == r.dx) {
                if (i || f > r.dy) f = r.dy;
                while (++s < o) {
                    l = e[s];
                    l.x = u;
                    l.y = a;
                    l.dy = f;
                    u += l.dx = Math.min(r.x + r.dx - u, f ? n(l.area / f) : 0);
                }
                l.z = !0;
                l.dx += r.x + r.dx - u;
                r.y += f;
                r.dy -= f;
            } else {
                if (i || f > r.dx) f = r.dx;
                while (++s < o) {
                    l = e[s];
                    l.x = u;
                    l.y = a;
                    l.dx = f;
                    a += l.dy = Math.min(r.y + r.dy - a, f ? n(l.area / f) : 0);
                }
                l.z = !1;
                l.dy += r.y + r.dy - a;
                r.x += f;
                r.dx -= f;
            }
        }
        function v(e) {
            var n = u || t(e), i = n[0];
            i.x = 0;
            i.y = 0;
            i.dx = r[0];
            i.dy = r[1];
            u && t.revalue(i);
            l([ i ], i.dx * i.dy / i.value);
            (u ? h : c)(i);
            o && (u = n);
            return n;
        }
        var t = e.layout.hierarchy(), n = Math.round, r = [ 1, 1 ], i = null, s = Eo, o = !1, u, a = "squarify", f = .5 * (1 + Math.sqrt(5));
        v.size = function(e) {
            if (!arguments.length) return r;
            r = e;
            return v;
        };
        v.padding = function(e) {
            function t(t) {
                var n = e.call(v, t, t.depth);
                return n == null ? Eo(t) : So(t, typeof n == "number" ? [ n, n, n, n ] : n);
            }
            function n(t) {
                return So(t, e);
            }
            if (!arguments.length) return i;
            var r;
            s = (i = e) == null ? Eo : (r = typeof e) === "function" ? t : r === "number" ? (e = [ e, e, e, e ], n) : n;
            return v;
        };
        v.round = function(e) {
            if (!arguments.length) return n != Number;
            n = e ? Math.round : Number;
            return v;
        };
        v.sticky = function(e) {
            if (!arguments.length) return o;
            o = e;
            u = null;
            return v;
        };
        v.ratio = function(e) {
            if (!arguments.length) return f;
            f = e;
            return v;
        };
        v.mode = function(e) {
            if (!arguments.length) return a;
            a = e + "";
            return v;
        };
        return Ms(v, t);
    };
    e.random = {
        normal: function(e, t) {
            var n = arguments.length;
            n < 2 && (t = 1);
            n < 1 && (e = 0);
            return function() {
                var n, r, i;
                do {
                    n = Math.random() * 2 - 1;
                    r = Math.random() * 2 - 1;
                    i = n * n + r * r;
                } while (!i || i > 1);
                return e + t * n * Math.sqrt(-2 * Math.log(i) / i);
            };
        },
        logNormal: function() {
            var t = e.random.normal.apply(e, arguments);
            return function() {
                return Math.exp(t());
            };
        },
        irwinHall: function(e) {
            return function() {
                for (var t = 0, n = 0; n < e; n++) t += Math.random();
                return t / e;
            };
        }
    };
    e.scale = {};
    e.scale.linear = function() {
        return Lo([ 0, 1 ], [ 0, 1 ], Qi, !1);
    };
    e.scale.log = function() {
        return Po(e.scale.linear().domain([ 0, Math.LN10 ]), 10, Bo, jo);
    };
    var Ho = e.format(".0e");
    e.scale.pow = function() {
        return Ro(e.scale.linear(), 1);
    };
    e.scale.sqrt = function() {
        return e.scale.pow().exponent(.5);
    };
    e.scale.ordinal = function() {
        return zo([], {
            t: "range",
            a: [ [] ]
        });
    };
    e.scale.category10 = function() {
        return e.scale.ordinal().range(Wo);
    };
    e.scale.category20 = function() {
        return e.scale.ordinal().range(Xo);
    };
    e.scale.category20b = function() {
        return e.scale.ordinal().range(Vo);
    };
    e.scale.category20c = function() {
        return e.scale.ordinal().range($o);
    };
    var Wo = [ "#1f77b4", "#ff7f0e", "#2ca02c", "#d62728", "#9467bd", "#8c564b", "#e377c2", "#7f7f7f", "#bcbd22", "#17becf" ], Xo = [ "#1f77b4", "#aec7e8", "#ff7f0e", "#ffbb78", "#2ca02c", "#98df8a", "#d62728", "#ff9896", "#9467bd", "#c5b0d5", "#8c564b", "#c49c94", "#e377c2", "#f7b6d2", "#7f7f7f", "#c7c7c7", "#bcbd22", "#dbdb8d", "#17becf", "#9edae5" ], Vo = [ "#393b79", "#5254a3", "#6b6ecf", "#9c9ede", "#637939", "#8ca252", "#b5cf6b", "#cedb9c", "#8c6d31", "#bd9e39", "#e7ba52", "#e7cb94", "#843c39", "#ad494a", "#d6616b", "#e7969c", "#7b4173", "#a55194", "#ce6dbd", "#de9ed6" ], $o = [ "#3182bd", "#6baed6", "#9ecae1", "#c6dbef", "#e6550d", "#fd8d3c", "#fdae6b", "#fdd0a2", "#31a354", "#74c476", "#a1d99b", "#c7e9c0", "#756bb1", "#9e9ac8", "#bcbddc", "#dadaeb", "#636363", "#969696", "#bdbdbd", "#d9d9d9" ];
    e.scale.quantile = function() {
        return Jo([], []);
    };
    e.scale.quantize = function() {
        return Ko(0, 1, [ 0, 1 ]);
    };
    e.scale.threshold = function() {
        return Qo([ .5 ], [ 0, 1 ]);
    };
    e.scale.identity = function() {
        return Go([ 0, 1 ]);
    };
    e.svg.arc = function() {
        function i() {
            var i = e.apply(this, arguments), s = t.apply(this, arguments), o = n.apply(this, arguments) + Yo, u = r.apply(this, arguments) + Yo, a = (u < o && (a = o, o = u, u = a), u - o), f = a < dt ? "0" : "1", l = Math.cos(o), c = Math.sin(o), h = Math.cos(u), p = Math.sin(u);
            return a >= Zo ? i ? "M0," + s + "A" + s + "," + s + " 0 1,1 0," + -s + "A" + s + "," + s + " 0 1,1 0," + s + "M0," + i + "A" + i + "," + i + " 0 1,0 0," + -i + "A" + i + "," + i + " 0 1,0 0," + i + "Z" : "M0," + s + "A" + s + "," + s + " 0 1,1 0," + -s + "A" + s + "," + s + " 0 1,1 0," + s + "Z" : i ? "M" + s * l + "," + s * c + "A" + s + "," + s + " 0 " + f + ",1 " + s * h + "," + s * p + "L" + i * h + "," + i * p + "A" + i + "," + i + " 0 " + f + ",0 " + i * l + "," + i * c + "Z" : "M" + s * l + "," + s * c + "A" + s + "," + s + " 0 " + f + ",1 " + s * h + "," + s * p + "L0,0" + "Z";
        }
        var e = eu, t = tu, n = nu, r = ru;
        i.innerRadius = function(t) {
            if (!arguments.length) return e;
            e = Qt(t);
            return i;
        };
        i.outerRadius = function(e) {
            if (!arguments.length) return t;
            t = Qt(e);
            return i;
        };
        i.startAngle = function(e) {
            if (!arguments.length) return n;
            n = Qt(e);
            return i;
        };
        i.endAngle = function(e) {
            if (!arguments.length) return r;
            r = Qt(e);
            return i;
        };
        i.centroid = function() {
            var i = (e.apply(this, arguments) + t.apply(this, arguments)) / 2, s = (n.apply(this, arguments) + r.apply(this, arguments)) / 2 + Yo;
            return [ Math.cos(s) * i, Math.sin(s) * i ];
        };
        return i;
    };
    var Yo = -dt / 2, Zo = 2 * dt - 1e-6;
    e.svg.line.radial = function() {
        var e = ii(iu);
        e.radius = e.x, delete e.x;
        e.angle = e.y, delete e.y;
        return e;
    };
    li.reverse = ci;
    ci.reverse = li;
    e.svg.area = function() {
        return su(Gt);
    };
    e.svg.area.radial = function() {
        var e = su(iu);
        e.radius = e.x, delete e.x;
        e.innerRadius = e.x0, delete e.x0;
        e.outerRadius = e.x1, delete e.x1;
        e.angle = e.y, delete e.y;
        e.startAngle = e.y0, delete e.y0;
        e.endAngle = e.y1, delete e.y1;
        return e;
    };
    e.svg.chord = function() {
        function s(n, r) {
            var i = o(this, e, n, r), s = o(this, t, n, r);
            return "M" + i.p0 + a(i.r, i.p1, i.a1 - i.a0) + (u(i, s) ? f(i.r, i.p1, i.r, i.p0) : f(i.r, i.p1, s.r, s.p0) + a(s.r, s.p1, s.a1 - s.a0) + f(s.r, s.p1, i.r, i.p0)) + "Z";
        }
        function o(e, t, s, o) {
            var u = t.call(e, s, o), a = n.call(e, u, o), f = r.call(e, u, o) + Yo, l = i.call(e, u, o) + Yo;
            return {
                r: a,
                a0: f,
                a1: l,
                p0: [ a * Math.cos(f), a * Math.sin(f) ],
                p1: [ a * Math.cos(l), a * Math.sin(l) ]
            };
        }
        function u(e, t) {
            return e.a0 == t.a0 && e.a1 == t.a1;
        }
        function a(e, t, n) {
            return "A" + e + "," + e + " 0 " + +(n > dt) + ",1 " + t;
        }
        function f(e, t, n, r) {
            return "Q 0,0 " + r;
        }
        var e = Nr, t = Cr, n = ou, r = nu, i = ru;
        s.radius = function(e) {
            if (!arguments.length) return n;
            n = Qt(e);
            return s;
        };
        s.source = function(t) {
            if (!arguments.length) return e;
            e = Qt(t);
            return s;
        };
        s.target = function(e) {
            if (!arguments.length) return t;
            t = Qt(e);
            return s;
        };
        s.startAngle = function(e) {
            if (!arguments.length) return r;
            r = Qt(e);
            return s;
        };
        s.endAngle = function(e) {
            if (!arguments.length) return i;
            i = Qt(e);
            return s;
        };
        return s;
    };
    e.svg.diagonal = function() {
        function r(r, i) {
            var s = e.call(this, r, i), o = t.call(this, r, i), u = (s.y + o.y) / 2, a = [ s, {
                x: s.x,
                y: u
            }, {
                x: o.x,
                y: u
            }, o ];
            a = a.map(n);
            return "M" + a[0] + "C" + a[1] + " " + a[2] + " " + a[3];
        }
        var e = Nr, t = Cr, n = uu;
        r.source = function(t) {
            if (!arguments.length) return e;
            e = Qt(t);
            return r;
        };
        r.target = function(e) {
            if (!arguments.length) return t;
            t = Qt(e);
            return r;
        };
        r.projection = function(e) {
            if (!arguments.length) return n;
            n = e;
            return r;
        };
        return r;
    };
    e.svg.diagonal.radial = function() {
        var t = e.svg.diagonal(), n = uu, r = t.projection;
        t.projection = function(e) {
            return arguments.length ? r(au(n = e)) : n;
        };
        return t;
    };
    e.svg.symbol = function() {
        function n(n, r) {
            return (hu.get(e.call(this, n, r)) || cu)(t.call(this, n, r));
        }
        var e = lu, t = fu;
        n.type = function(t) {
            if (!arguments.length) return e;
            e = Qt(t);
            return n;
        };
        n.size = function(e) {
            if (!arguments.length) return t;
            t = Qt(e);
            return n;
        };
        return n;
    };
    var hu = e.map({
        circle: cu,
        cross: function(e) {
            var t = Math.sqrt(e / 5) / 2;
            return "M" + -3 * t + "," + -t + "H" + -t + "V" + -3 * t + "H" + t + "V" + -t + "H" + 3 * t + "V" + t + "H" + t + "V" + 3 * t + "H" + -t + "V" + t + "H" + -3 * t + "Z";
        },
        diamond: function(e) {
            var t = Math.sqrt(e / (2 * du)), n = t * du;
            return "M0," + -t + "L" + n + ",0" + " 0," + t + " " + -n + ",0" + "Z";
        },
        square: function(e) {
            var t = Math.sqrt(e) / 2;
            return "M" + -t + "," + -t + "L" + t + "," + -t + " " + t + "," + t + " " + -t + "," + t + "Z";
        },
        "triangle-down": function(e) {
            var t = Math.sqrt(e / pu), n = t * pu / 2;
            return "M0," + n + "L" + t + "," + -n + " " + -t + "," + -n + "Z";
        },
        "triangle-up": function(e) {
            var t = Math.sqrt(e / pu), n = t * pu / 2;
            return "M0," + -n + "L" + t + "," + n + " " + -t + "," + n + "Z";
        }
    });
    e.svg.symbolTypes = hu.keys();
    var pu = Math.sqrt(3), du = Math.tan(30 * mt), mu = [], gu = 0, yu, bu = {
        ease: us,
        delay: 0,
        duration: 250
    };
    mu.call = B.call;
    mu.empty = B.empty;
    mu.node = B.node;
    e.transition = function(e) {
        return arguments.length ? yu ? e.transition() : e : st.transition();
    };
    e.transition.prototype = mu;
    mu.select = function(e) {
        var t = this.id, n = [], r, i, s;
        typeof e != "function" && (e = j(e));
        for (var o = -1, u = this.length; ++o < u; ) {
            n.push(r = []);
            for (var a = this[o], f = -1, l = a.length; ++f < l; ) if ((s = a[f]) && (i = e.call(s, s.__data__, f))) {
                "__data__" in s && (i.__data__ = s.__data__);
                Su(i, f, t, s.__transition__[t]);
                r.push(i);
            } else r.push(null);
        }
        return vu(n, t);
    };
    mu.selectAll = function(e) {
        var t = this.id, n = [], r, i, s, o, u;
        typeof e != "function" && (e = F(e));
        for (var a = -1, f = this.length; ++a < f; ) for (var l = this[a], c = -1, h = l.length; ++c < h; ) if (s = l[c]) {
            u = s.__transition__[t];
            i = e.call(s, s.__data__, c);
            n.push(r = []);
            for (var p = -1, d = i.length; ++p < d; ) {
                Su(o = i[p], p, t, u);
                r.push(o);
            }
        }
        return vu(n, t);
    };
    mu.filter = function(e) {
        var t = [], n, r, i;
        typeof e != "function" && (e = K(e));
        for (var s = 0, o = this.length; s < o; s++) {
            t.push(n = []);
            for (var r = this[s], u = 0, a = r.length; u < a; u++) (i = r[u]) && e.call(i, i.__data__, u) && n.push(i);
        }
        return vu(t, this.id, this.time).ease(this.ease());
    };
    mu.tween = function(e, t) {
        var n = this.id;
        return arguments.length < 2 ? this.node().__transition__[n].tween.get(e) : nt(this, t == null ? function(t) {
            t.__transition__[n].tween.remove(e);
        } : function(r) {
            r.__transition__[n].tween.set(e, t);
        });
    };
    mu.attr = function(t, n) {
        function s() {
            this.removeAttribute(i);
        }
        function o() {
            this.removeAttributeNS(i.space, i.local);
        }
        if (arguments.length < 2) {
            for (n in t) this.attr(n, t[n]);
            return this;
        }
        var r = Gi(t), i = e.ns.qualify(t);
        return wu(this, "attr." + t, n, function(e) {
            function t() {
                var t = this.getAttribute(i), n;
                return t !== e && (n = r(t, e), function(e) {
                    this.setAttribute(i, n(e));
                });
            }
            function n() {
                var t = this.getAttributeNS(i.space, i.local), n;
                return t !== e && (n = r(t, e), function(e) {
                    this.setAttributeNS(i.space, i.local, n(e));
                });
            }
            return e == null ? i.local ? o : s : (e += "", i.local ? n : t);
        });
    };
    mu.attrTween = function(t, n) {
        function i(e, t) {
            var i = n.call(this, e, t, this.getAttribute(r));
            return i && function(e) {
                this.setAttribute(r, i(e));
            };
        }
        function s(e, t) {
            var i = n.call(this, e, t, this.getAttributeNS(r.space, r.local));
            return i && function(e) {
                this.setAttributeNS(r.space, r.local, i(e));
            };
        }
        var r = e.ns.qualify(t);
        return this.tween("attr." + t, r.local ? s : i);
    };
    mu.style = function(e, t, r) {
        function o() {
            this.style.removeProperty(e);
        }
        var i = arguments.length;
        if (i < 3) {
            if (typeof e != "string") {
                i < 2 && (t = "");
                for (r in e) this.style(r, e[r], t);
                return this;
            }
            r = "";
        }
        var s = Gi(e);
        return wu(this, "style." + e, t, function(t) {
            function i() {
                var i = n.getComputedStyle(this, null).getPropertyValue(e), o;
                return i !== t && (o = s(i, t), function(t) {
                    this.style.setProperty(e, o(t), r);
                });
            }
            return t == null ? o : (t += "", i);
        });
    };
    mu.styleTween = function(e, t, r) {
        arguments.length < 3 && (r = "");
        return this.tween("style." + e, function(i, s) {
            var o = t.call(this, i, s, n.getComputedStyle(this, null).getPropertyValue(e));
            return o && function(t) {
                this.style.setProperty(e, o(t), r);
            };
        });
    };
    mu.text = function(e) {
        return wu(this, "text", e, Eu);
    };
    mu.remove = function() {
        return this.each("end.transition", function() {
            var e;
            !this.__transition__ && (e = this.parentNode) && e.removeChild(this);
        });
    };
    mu.ease = function(t) {
        var n = this.id;
        if (arguments.length < 1) return this.node().__transition__[n].ease;
        typeof t != "function" && (t = e.ease.apply(e, arguments));
        return nt(this, function(e) {
            e.__transition__[n].ease = t;
        });
    };
    mu.delay = function(e) {
        var t = this.id;
        return nt(this, typeof e == "function" ? function(n, r, i) {
            n.__transition__[t].delay = e.call(n, n.__data__, r, i) | 0;
        } : (e |= 0, function(n) {
            n.__transition__[t].delay = e;
        }));
    };
    mu.duration = function(e) {
        var t = this.id;
        return nt(this, typeof e == "function" ? function(n, r, i) {
            n.__transition__[t].duration = Math.max(1, e.call(n, n.__data__, r, i) | 0);
        } : (e = Math.max(1, e | 0), function(n) {
            n.__transition__[t].duration = e;
        }));
    };
    mu.each = function(e, t) {
        var n = this.id;
        if (arguments.length < 2) {
            var r = bu, i = yu;
            yu = n;
            nt(this, function(t, r, i) {
                bu = t.__transition__[n];
                e.call(t, t.__data__, r, i);
            });
            bu = r;
            yu = i;
        } else nt(this, function(r) {
            r.__transition__[n].event.on(e, t);
        });
        return this;
    };
    mu.transition = function() {
        var e = this.id, t = ++gu, n = [], r, i, s, o;
        for (var u = 0, a = this.length; u < a; u++) {
            n.push(r = []);
            for (var i = this[u], f = 0, l = i.length; f < l; f++) {
                if (s = i[f]) {
                    o = Object.create(s.__transition__[e]);
                    o.delay += o.duration;
                    Su(s, f, t, o);
                }
                r.push(s);
            }
        }
        return vu(n, t);
    };
    e.svg.axis = function() {
        function c(c) {
            c.each(function() {
                var c = e.select(this), h = a == null ? t.ticks ? t.ticks.apply(t, u) : t.domain() : a, p = f == null ? t.tickFormat ? t.tickFormat.apply(t, u) : String : f, d = ku(t, h, l), v = c.selectAll(".tick.minor").data(d, String), m = v.enter().insert("line", ".tick").attr("class", "tick minor").style("opacity", 1e-6), g = e.transition(v.exit()).style("opacity", 1e-6).remove(), y = e.transition(v).style("opacity", 1), b = c.selectAll(".tick.major").data(h, String), w = b.enter().insert("g", "path").attr("class", "tick major").style("opacity", 1e-6), E = e.transition(b.exit()).style("opacity", 1e-6).remove(), S = e.transition(b).style("opacity", 1), x, T = To(t), N = c.selectAll(".domain").data([ 0 ]), C = (N.enter().append("path").attr("class", "domain"), e.transition(N)), k = t.copy(), L = this.__chart__ || k;
                this.__chart__ = k;
                w.append("line");
                w.append("text");
                var A = w.select("line"), O = S.select("line"), M = b.select("text").text(p), _ = w.select("text"), D = S.select("text");
                switch (n) {
                  case "bottom":
                    x = Nu;
                    m.attr("y2", i);
                    y.attr("x2", 0).attr("y2", i);
                    A.attr("y2", r);
                    _.attr("y", Math.max(r, 0) + o);
                    O.attr("x2", 0).attr("y2", r);
                    D.attr("x", 0).attr("y", Math.max(r, 0) + o);
                    M.attr("dy", ".71em").style("text-anchor", "middle");
                    C.attr("d", "M" + T[0] + "," + s + "V0H" + T[1] + "V" + s);
                    break;
                  case "top":
                    x = Nu;
                    m.attr("y2", -i);
                    y.attr("x2", 0).attr("y2", -i);
                    A.attr("y2", -r);
                    _.attr("y", -(Math.max(r, 0) + o));
                    O.attr("x2", 0).attr("y2", -r);
                    D.attr("x", 0).attr("y", -(Math.max(r, 0) + o));
                    M.attr("dy", "0em").style("text-anchor", "middle");
                    C.attr("d", "M" + T[0] + "," + -s + "V0H" + T[1] + "V" + -s);
                    break;
                  case "left":
                    x = Cu;
                    m.attr("x2", -i);
                    y.attr("x2", -i).attr("y2", 0);
                    A.attr("x2", -r);
                    _.attr("x", -(Math.max(r, 0) + o));
                    O.attr("x2", -r).attr("y2", 0);
                    D.attr("x", -(Math.max(r, 0) + o)).attr("y", 0);
                    M.attr("dy", ".32em").style("text-anchor", "end");
                    C.attr("d", "M" + -s + "," + T[0] + "H0V" + T[1] + "H" + -s);
                    break;
                  case "right":
                    x = Cu;
                    m.attr("x2", i);
                    y.attr("x2", i).attr("y2", 0);
                    A.attr("x2", r);
                    _.attr("x", Math.max(r, 0) + o);
                    O.attr("x2", r).attr("y2", 0);
                    D.attr("x", Math.max(r, 0) + o).attr("y", 0);
                    M.attr("dy", ".32em").style("text-anchor", "start");
                    C.attr("d", "M" + s + "," + T[0] + "H0V" + T[1] + "H" + s);
                }
                if (t.ticks) {
                    w.call(x, L);
                    S.call(x, k);
                    E.call(x, k);
                    m.call(x, L);
                    y.call(x, k);
                    g.call(x, k);
                } else {
                    var P = k.rangeBand() / 2, H = function(e) {
                        return k(e) + P;
                    };
                    w.call(x, H);
                    S.call(x, H);
                }
            });
        }
        var t = e.scale.linear(), n = xu, r = 6, i = 6, s = 6, o = 3, u = [ 10 ], a = null, f, l = 0;
        c.scale = function(e) {
            if (!arguments.length) return t;
            t = e;
            return c;
        };
        c.orient = function(e) {
            if (!arguments.length) return n;
            n = e in Tu ? e + "" : xu;
            return c;
        };
        c.ticks = function() {
            if (!arguments.length) return u;
            u = arguments;
            return c;
        };
        c.tickValues = function(e) {
            if (!arguments.length) return a;
            a = e;
            return c;
        };
        c.tickFormat = function(e) {
            if (!arguments.length) return f;
            f = e;
            return c;
        };
        c.tickSize = function(e, t) {
            if (!arguments.length) return r;
            var n = arguments.length - 1;
            r = +e;
            i = n > 1 ? +t : r;
            s = n > 0 ? +arguments[n] : r;
            return c;
        };
        c.tickPadding = function(e) {
            if (!arguments.length) return o;
            o = +e;
            return c;
        };
        c.tickSubdivide = function(e) {
            if (!arguments.length) return l;
            l = +e;
            return c;
        };
        return c;
    };
    var xu = "bottom", Tu = {
        top: 1,
        right: 1,
        bottom: 1,
        left: 1
    };
    e.svg.brush = function() {
        function a(t) {
            t.each(function() {
                var t = e.select(this), n = t.selectAll(".background").data([ 0 ]), o = t.selectAll(".extent").data([ 0 ]), u = t.selectAll(".resize").data(s, String), p;
                t.style("pointer-events", "all").on("mousedown.brush", h).on("touchstart.brush", h);
                n.enter().append("rect").attr("class", "background").style("visibility", "hidden").style("cursor", "crosshair");
                o.enter().append("rect").attr("class", "extent").style("cursor", "move");
                u.enter().append("g").attr("class", function(e) {
                    return "resize " + e;
                }).style("cursor", function(e) {
                    return Lu[e];
                }).append("rect").attr("x", function(e) {
                    return /[ew]$/.test(e) ? -3 : null;
                }).attr("y", function(e) {
                    return /^[ns]/.test(e) ? -3 : null;
                }).attr("width", 6).attr("height", 6).style("visibility", "hidden");
                u.style("display", a.empty() ? "none" : null);
                u.exit().remove();
                if (r) {
                    p = To(r);
                    n.attr("x", p[0]).attr("width", p[1] - p[0]);
                    l(t);
                }
                if (i) {
                    p = To(i);
                    n.attr("y", p[0]).attr("height", p[1] - p[0]);
                    c(t);
                }
                f(t);
            });
        }
        function f(e) {
            e.selectAll(".resize").attr("transform", function(e) {
                return "translate(" + o[+/e$/.test(e)][0] + "," + o[+/^s/.test(e)][1] + ")";
            });
        }
        function l(e) {
            e.select(".extent").attr("x", o[0][0]);
            e.selectAll(".extent,.n>rect,.s>rect").attr("width", o[1][0] - o[0][0]);
        }
        function c(e) {
            e.select(".extent").attr("y", o[0][1]);
            e.selectAll(".extent,.e>rect,.w>rect").attr("height", o[1][1] - o[0][1]);
        }
        function h() {
            function C() {
                var t = e.event.changedTouches;
                return t ? e.touches(s, t)[0] : e.mouse(s);
            }
            function k() {
                if (e.event.keyCode == 32) {
                    if (!b) {
                        w = null;
                        E[0] -= o[1][0];
                        E[1] -= o[1][1];
                        b = 2;
                    }
                    y();
                }
            }
            function L() {
                if (e.event.keyCode == 32 && b == 2) {
                    E[0] += o[1][0];
                    E[1] += o[1][1];
                    b = 0;
                    y();
                }
            }
            function A() {
                var t = C(), n = !1;
                if (S) {
                    t[0] += S[0];
                    t[1] += S[1];
                }
                if (!b) if (e.event.altKey) {
                    w || (w = [ (o[0][0] + o[1][0]) / 2, (o[0][1] + o[1][1]) / 2 ]);
                    E[0] = o[+(t[0] < w[0])][0];
                    E[1] = o[+(t[1] < w[1])][1];
                } else w = null;
                if (m && O(t, r, 0)) {
                    l(d);
                    n = !0;
                }
                if (g && O(t, i, 1)) {
                    c(d);
                    n = !0;
                }
                if (n) {
                    f(d);
                    p({
                        type: "brush",
                        mode: b ? "move" : "resize"
                    });
                }
            }
            function O(e, t, n) {
                var r = To(t), i = r[0], s = r[1], a = E[n], f = o[1][n] - o[0][n], l, c;
                if (b) {
                    i -= a;
                    s -= f + a;
                }
                l = Math.max(i, Math.min(s, e[n]));
                if (b) c = (l += a) + f; else {
                    w && (a = Math.max(i, Math.min(s, 2 * w[n] - l)));
                    if (a < l) {
                        c = l;
                        l = a;
                    } else c = a;
                }
                if (o[0][n] !== l || o[1][n] !== c) {
                    u = null;
                    o[0][n] = l;
                    o[1][n] = c;
                    return !0;
                }
            }
            function M() {
                A();
                d.style("pointer-events", "all").selectAll(".resize").style("display", a.empty() ? "none" : null);
                e.select("body").style("cursor", null);
                x.on("mousemove.brush", null).on("mouseup.brush", null).on("touchmove.brush", null).on("touchend.brush", null).on("keydown.brush", null).on("keyup.brush", null);
                p({
                    type: "brushend"
                });
                y();
            }
            var s = this, h = e.select(e.event.target), p = t.of(s, arguments), d = e.select(s), v = h.datum(), m = !/^(n|s)$/.test(v) && r, g = !/^(e|w)$/.test(v) && i, b = h.classed("extent"), w, E = C(), S, x = e.select(n).on("mousemove.brush", A).on("mouseup.brush", M).on("touchmove.brush", A).on("touchend.brush", M).on("keydown.brush", k).on("keyup.brush", L);
            if (b) {
                E[0] = o[0][0] - E[0];
                E[1] = o[0][1] - E[1];
            } else if (v) {
                var T = +/w$/.test(v), N = +/^n/.test(v);
                S = [ o[1 - T][0] - E[0], o[1 - N][1] - E[1] ];
                E[0] = o[T][0];
                E[1] = o[N][1];
            } else e.event.altKey && (w = E.slice());
            d.style("pointer-events", "none").selectAll(".resize").style("display", null);
            e.select("body").style("cursor", h.style("cursor"));
            p({
                type: "brushstart"
            });
            A();
            y();
        }
        var t = S(a, "brushstart", "brush", "brushend"), r = null, i = null, s = Au[0], o = [ [ 0, 0 ], [ 0, 0 ] ], u;
        a.x = function(e) {
            if (!arguments.length) return r;
            r = e;
            s = Au[!r << 1 | !i];
            return a;
        };
        a.y = function(e) {
            if (!arguments.length) return i;
            i = e;
            s = Au[!r << 1 | !i];
            return a;
        };
        a.extent = function(e) {
            var t, n, s, f, l;
            if (!arguments.length) {
                e = u || o;
                if (r) {
                    t = e[0][0], n = e[1][0];
                    if (!u) {
                        t = o[0][0], n = o[1][0];
                        r.invert && (t = r.invert(t), n = r.invert(n));
                        n < t && (l = t, t = n, n = l);
                    }
                }
                if (i) {
                    s = e[0][1], f = e[1][1];
                    if (!u) {
                        s = o[0][1], f = o[1][1];
                        i.invert && (s = i.invert(s), f = i.invert(f));
                        f < s && (l = s, s = f, f = l);
                    }
                }
                return r && i ? [ [ t, s ], [ n, f ] ] : r ? [ t, n ] : i && [ s, f ];
            }
            u = [ [ 0, 0 ], [ 0, 0 ] ];
            if (r) {
                t = e[0], n = e[1];
                i && (t = t[0], n = n[0]);
                u[0][0] = t, u[1][0] = n;
                r.invert && (t = r(t), n = r(n));
                n < t && (l = t, t = n, n = l);
                o[0][0] = t | 0, o[1][0] = n | 0;
            }
            if (i) {
                s = e[0], f = e[1];
                r && (s = s[1], f = f[1]);
                u[0][1] = s, u[1][1] = f;
                i.invert && (s = i(s), f = i(f));
                f < s && (l = s, s = f, f = l);
                o[0][1] = s | 0, o[1][1] = f | 0;
            }
            return a;
        };
        a.clear = function() {
            u = null;
            o[0][0] = o[0][1] = o[1][0] = o[1][1] = 0;
            return a;
        };
        a.empty = function() {
            return r && o[0][0] === o[1][0] || i && o[0][1] === o[1][1];
        };
        return e.rebind(a, t, "on");
    };
    var Lu = {
        n: "ns-resize",
        e: "ew-resize",
        s: "ns-resize",
        w: "ew-resize",
        nw: "nwse-resize",
        ne: "nesw-resize",
        se: "nwse-resize",
        sw: "nesw-resize"
    }, Au = [ [ "n", "e", "s", "w", "nw", "ne", "se", "sw" ], [ "e", "w" ], [ "n", "s" ], [] ];
    e.time = {};
    var Ou = Date, Mu = [ "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" ];
    _u.prototype = {
        getDate: function() {
            return this._.getUTCDate();
        },
        getDay: function() {
            return this._.getUTCDay();
        },
        getFullYear: function() {
            return this._.getUTCFullYear();
        },
        getHours: function() {
            return this._.getUTCHours();
        },
        getMilliseconds: function() {
            return this._.getUTCMilliseconds();
        },
        getMinutes: function() {
            return this._.getUTCMinutes();
        },
        getMonth: function() {
            return this._.getUTCMonth();
        },
        getSeconds: function() {
            return this._.getUTCSeconds();
        },
        getTime: function() {
            return this._.getTime();
        },
        getTimezoneOffset: function() {
            return 0;
        },
        valueOf: function() {
            return this._.valueOf();
        },
        setDate: function() {
            Du.setUTCDate.apply(this._, arguments);
        },
        setDay: function() {
            Du.setUTCDay.apply(this._, arguments);
        },
        setFullYear: function() {
            Du.setUTCFullYear.apply(this._, arguments);
        },
        setHours: function() {
            Du.setUTCHours.apply(this._, arguments);
        },
        setMilliseconds: function() {
            Du.setUTCMilliseconds.apply(this._, arguments);
        },
        setMinutes: function() {
            Du.setUTCMinutes.apply(this._, arguments);
        },
        setMonth: function() {
            Du.setUTCMonth.apply(this._, arguments);
        },
        setSeconds: function() {
            Du.setUTCSeconds.apply(this._, arguments);
        },
        setTime: function() {
            Du.setTime.apply(this._, arguments);
        }
    };
    var Du = Date.prototype, Pu = "%a %b %e %X %Y", Hu = "%m/%d/%Y", Bu = "%H:%M:%S", ju = [ "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" ], Fu = [ "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" ], Iu = [ "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" ], qu = [ "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" ];
    e.time.year = Ru(function(t) {
        t = e.time.day(t);
        t.setMonth(0, 1);
        return t;
    }, function(e, t) {
        e.setFullYear(e.getFullYear() + t);
    }, function(e) {
        return e.getFullYear();
    });
    e.time.years = e.time.year.range;
    e.time.years.utc = e.time.year.utc.range;
    e.time.day = Ru(function(e) {
        var t = new Ou(1970, 0);
        t.setFullYear(e.getFullYear(), e.getMonth(), e.getDate());
        return t;
    }, function(e, t) {
        e.setDate(e.getDate() + t);
    }, function(e) {
        return e.getDate() - 1;
    });
    e.time.days = e.time.day.range;
    e.time.days.utc = e.time.day.utc.range;
    e.time.dayOfYear = function(t) {
        var n = e.time.year(t);
        return Math.floor((t - n - (t.getTimezoneOffset() - n.getTimezoneOffset()) * 6e4) / 864e5);
    };
    Mu.forEach(function(t, n) {
        t = t.toLowerCase();
        n = 7 - n;
        var r = e.time[t] = Ru(function(t) {
            (t = e.time.day(t)).setDate(t.getDate() - (t.getDay() + n) % 7);
            return t;
        }, function(e, t) {
            e.setDate(e.getDate() + Math.floor(t) * 7);
        }, function(t) {
            var r = e.time.year(t).getDay();
            return Math.floor((e.time.dayOfYear(t) + (r + n) % 7) / 7) - (r !== n);
        });
        e.time[t + "s"] = r.range;
        e.time[t + "s"].utc = r.utc.range;
        e.time[t + "OfYear"] = function(t) {
            var r = e.time.year(t).getDay();
            return Math.floor((e.time.dayOfYear(t) + (r + n) % 7) / 7);
        };
    });
    e.time.week = e.time.sunday;
    e.time.weeks = e.time.sunday.range;
    e.time.weeks.utc = e.time.sunday.utc.range;
    e.time.weekOfYear = e.time.sundayOfYear;
    e.time.format = function(e) {
        function n(n) {
            var r = [], i = -1, s = 0, o, u, a;
            while (++i < t) if (e.charCodeAt(i) === 37) {
                r.push(e.substring(s, i));
                (u = Zu[o = e.charAt(++i)]) != null && (o = e.charAt(++i));
                if (a = ea[o]) o = a(n, u == null ? o === "e" ? " " : "0" : u);
                r.push(o);
                s = i + 1;
            }
            r.push(e.substring(s, i));
            return r.join("");
        }
        var t = e.length;
        n.parse = function(t) {
            var n = {
                y: 1900,
                m: 0,
                d: 1,
                H: 0,
                M: 0,
                S: 0,
                L: 0
            }, r = zu(n, e, t, 0);
            if (r != t.length) return null;
            "p" in n && (n.H = n.H % 12 + n.p * 12);
            var i = new Ou;
            i.setFullYear(n.y, n.m, n.d);
            i.setHours(n.H, n.M, n.S, n.L);
            return i;
        };
        n.toString = function() {
            return e;
        };
        return n;
    };
    var $u = Wu(ju), Ju = Wu(Fu), Ku = Wu(Iu), Qu = Xu(Iu), Gu = Wu(qu), Yu = Xu(qu), Zu = {
        "-": "",
        _: " ",
        "0": "0"
    }, ea = {
        a: function(e) {
            return Fu[e.getDay()];
        },
        A: function(e) {
            return ju[e.getDay()];
        },
        b: function(e) {
            return qu[e.getMonth()];
        },
        B: function(e) {
            return Iu[e.getMonth()];
        },
        c: e.time.format(Pu),
        d: function(e, t) {
            return Vu(e.getDate(), t, 2);
        },
        e: function(e, t) {
            return Vu(e.getDate(), t, 2);
        },
        H: function(e, t) {
            return Vu(e.getHours(), t, 2);
        },
        I: function(e, t) {
            return Vu(e.getHours() % 12 || 12, t, 2);
        },
        j: function(t, n) {
            return Vu(1 + e.time.dayOfYear(t), n, 3);
        },
        L: function(e, t) {
            return Vu(e.getMilliseconds(), t, 3);
        },
        m: function(e, t) {
            return Vu(e.getMonth() + 1, t, 2);
        },
        M: function(e, t) {
            return Vu(e.getMinutes(), t, 2);
        },
        p: function(e) {
            return e.getHours() >= 12 ? "PM" : "AM";
        },
        S: function(e, t) {
            return Vu(e.getSeconds(), t, 2);
        },
        U: function(t, n) {
            return Vu(e.time.sundayOfYear(t), n, 2);
        },
        w: function(e) {
            return e.getDay();
        },
        W: function(t, n) {
            return Vu(e.time.mondayOfYear(t), n, 2);
        },
        x: e.time.format(Hu),
        X: e.time.format(Bu),
        y: function(e, t) {
            return Vu(e.getFullYear() % 100, t, 2);
        },
        Y: function(e, t) {
            return Vu(e.getFullYear() % 1e4, t, 4);
        },
        Z: Ea,
        "%": function() {
            return "%";
        }
    }, ta = {
        a: na,
        A: ra,
        b: ia,
        B: sa,
        c: oa,
        d: pa,
        e: pa,
        H: da,
        I: da,
        L: ga,
        m: ha,
        M: va,
        p: ba,
        S: ma,
        x: ua,
        X: aa,
        y: la,
        Y: fa
    }, ya = /^\s*\d+/, wa = e.map({
        am: 0,
        pm: 1
    });
    e.time.format.utc = function(t) {
        function r(e) {
            try {
                Ou = _u;
                var t = new Ou;
                t._ = e;
                return n(t);
            } finally {
                Ou = Date;
            }
        }
        var n = e.time.format(t);
        r.parse = function(e) {
            try {
                Ou = _u;
                var t = n.parse(e);
                return t && t._;
            } finally {
                Ou = Date;
            }
        };
        r.toString = n.toString;
        return r;
    };
    var Sa = e.time.format.utc("%Y-%m-%dT%H:%M:%S.%LZ");
    e.time.format.iso = Date.prototype.toISOString && +(new Date("2000-01-01T00:00:00.000Z")) ? xa : Sa;
    xa.parse = function(e) {
        var t = new Date(e);
        return isNaN(t) ? null : t;
    };
    xa.toString = Sa.toString;
    e.time.second = Ru(function(e) {
        return new Ou(Math.floor(e / 1e3) * 1e3);
    }, function(e, t) {
        e.setTime(e.getTime() + Math.floor(t) * 1e3);
    }, function(e) {
        return e.getSeconds();
    });
    e.time.seconds = e.time.second.range;
    e.time.seconds.utc = e.time.second.utc.range;
    e.time.minute = Ru(function(e) {
        return new Ou(Math.floor(e / 6e4) * 6e4);
    }, function(e, t) {
        e.setTime(e.getTime() + Math.floor(t) * 6e4);
    }, function(e) {
        return e.getMinutes();
    });
    e.time.minutes = e.time.minute.range;
    e.time.minutes.utc = e.time.minute.utc.range;
    e.time.hour = Ru(function(e) {
        var t = e.getTimezoneOffset() / 60;
        return new Ou((Math.floor(e / 36e5 - t) + t) * 36e5);
    }, function(e, t) {
        e.setTime(e.getTime() + Math.floor(t) * 36e5);
    }, function(e) {
        return e.getHours();
    });
    e.time.hours = e.time.hour.range;
    e.time.hours.utc = e.time.hour.utc.range;
    e.time.month = Ru(function(t) {
        t = e.time.day(t);
        t.setDate(1);
        return t;
    }, function(e, t) {
        e.setMonth(e.getMonth() + t);
    }, function(e) {
        return e.getMonth();
    });
    e.time.months = e.time.month.range;
    e.time.months.utc = e.time.month.utc.range;
    var Oa = [ 1e3, 5e3, 15e3, 3e4, 6e4, 3e5, 9e5, 18e5, 36e5, 108e5, 216e5, 432e5, 864e5, 1728e5, 6048e5, 2592e6, 7776e6, 31536e6 ], Ma = [ [ e.time.second, 1 ], [ e.time.second, 5 ], [ e.time.second, 15 ], [ e.time.second, 30 ], [ e.time.minute, 1 ], [ e.time.minute, 5 ], [ e.time.minute, 15 ], [ e.time.minute, 30 ], [ e.time.hour, 1 ], [ e.time.hour, 3 ], [ e.time.hour, 6 ], [ e.time.hour, 12 ], [ e.time.day, 1 ], [ e.time.day, 2 ], [ e.time.week, 1 ], [ e.time.month, 1 ], [ e.time.month, 3 ], [ e.time.year, 1 ] ], _a = [ [ e.time.format("%Y"), $n ], [ e.time.format("%B"), function(e) {
        return e.getMonth();
    } ], [ e.time.format("%b %d"), function(e) {
        return e.getDate() != 1;
    } ], [ e.time.format("%a %d"), function(e) {
        return e.getDay() && e.getDate() != 1;
    } ], [ e.time.format("%I %p"), function(e) {
        return e.getHours();
    } ], [ e.time.format("%I:%M"), function(e) {
        return e.getMinutes();
    } ], [ e.time.format(":%S"), function(e) {
        return e.getSeconds();
    } ], [ e.time.format(".%L"), function(e) {
        return e.getMilliseconds();
    } ] ], Da = e.scale.linear(), Pa = ka(_a);
    Ma.year = function(e, t) {
        return Da.domain(e.map(Aa)).ticks(t).map(La);
    };
    e.time.scale = function() {
        return Ta(e.scale.linear(), Ma, Pa);
    };
    var Ha = Ma.map(function(e) {
        return [ e[0].utc, e[1] ];
    }), Ba = [ [ e.time.format.utc("%Y"), $n ], [ e.time.format.utc("%B"), function(e) {
        return e.getUTCMonth();
    } ], [ e.time.format.utc("%b %d"), function(e) {
        return e.getUTCDate() != 1;
    } ], [ e.time.format.utc("%a %d"), function(e) {
        return e.getUTCDay() && e.getUTCDate() != 1;
    } ], [ e.time.format.utc("%I %p"), function(e) {
        return e.getUTCHours();
    } ], [ e.time.format.utc("%I:%M"), function(e) {
        return e.getUTCMinutes();
    } ], [ e.time.format.utc(":%S"), function(e) {
        return e.getUTCSeconds();
    } ], [ e.time.format.utc(".%L"), function(e) {
        return e.getUTCMilliseconds();
    } ] ], ja = ka(Ba);
    Ha.year = function(e, t) {
        return Da.domain(e.map(Ia)).ticks(t).map(Fa);
    };
    e.time.scale.utc = function() {
        return Ta(e.scale.linear(), Ha, ja);
    };
    e.text = function() {
        return e.xhr.apply(e, arguments).response(qa);
    };
    e.json = function(t, n) {
        return e.xhr(t, "application/json", n).response(Ra);
    };
    e.html = function(t, n) {
        return e.xhr(t, "text/html", n).response(Ua);
    };
    e.xml = function() {
        return e.xhr.apply(e, arguments).response(za);
    };
    return e;
}();